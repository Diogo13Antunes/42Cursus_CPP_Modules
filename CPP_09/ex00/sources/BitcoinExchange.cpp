#include <BitcoinExchange.hpp>

#define	MONTH_INDEX	0
#define	DAY_INDEX	1

static bool		isValidLine(std::string date, std::string value);
static bool		isValidDate(std::string date);
static bool		isValidValue(std::string value);
static bool		printErrorMessages(std::string error);
static time_t	convertStrToTimestamp(std::string date);
static std::string	convertTimestampToString(std::time_t rawtime);

BitcoinExchange::BitcoinExchange(void)
{
	this->dataBaseFileName = "data.csv";
	setDataBase(this->dataBaseFileName.c_str());
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	//BitcoinExchange Copy Constructor
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//Default BitcoinExchange Destructor
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	//BitcoinExchange Copy Assignment Operator
	this->dataBaseFileName = src.dataBaseFileName;
	this->dataBase = src.dataBase;
	return (*this);
}

void	BitcoinExchange::setDataBase(const char *dataBaseFileName)
{
	std::fstream	file;
	std::string		tempString;
	std::string		date;
	std::string		value;
	std::size_t		index;

	file.open(dataBaseFileName, std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Impossible to read from date.csv file" << std::endl;
		exit(1);
	}
	std::getline(file, tempString);
	tempString.clear();
	while (1)
	{
		std::getline(file, tempString);
		if (tempString.empty())
			break;
		index = tempString.find_first_of(',', 0);
		date = tempString.substr(0, index);
		value = tempString.substr(index + 1, tempString.length());
		this->dataBase.insert(std::pair<std::string, std::string>(date, value));
	}
}

void	BitcoinExchange::exchanger(char *fileName)
{
	std::fstream	file;
	std::string		tempString;
	std::string		date;
	std::string		value;
	std::size_t		index;

	file.open(fileName, std::ios::in);
	std::getline(file, tempString);
	while (1)
	{
		std::getline(file, tempString);
		if (file.eof() != 0)
			break;
		if (tempString.find_first_not_of("0123456789.|- ") != tempString.npos || tempString.empty())
			std::cout << "Invalid input! Correct form: YYYY-MM-DD | value (0 > 1000)" << std::endl;
		else
		{
			index = tempString.find_first_of(' ', 0);
			date = tempString.substr(0, index);
			value = tempString.substr(index + 3, tempString.length());
			if (isValidLine(date, value) == true)
				makeExchange(date, value);
		}
	}
}

void	BitcoinExchange::makeExchange(std::string date, std::string value)
{
	float		dateValue;
	float		amountValue;
	float		result = 0;
	std::string	newDate;
	time_t		timestamp;

	timestamp = convertStrToTimestamp(date);
	while (1)
	{
		newDate = convertTimestampToString(timestamp);
		if (this->dataBase.count(newDate) == 1)
		{
			dateValue = std::atof(this->dataBase[newDate].c_str());
			amountValue = std::atof(value.c_str());
			result = amountValue * dateValue;
			break;
		}
		timestamp = timestamp - 86400;
	}
	std::cout << date << " => " << value << " = " << result << std::endl;
}

static time_t	convertStrToTimestamp(std::string date)
{
	struct tm	t;
	std::time_t	timestamp;
	std::string	year;
	std::string	month;
	std::string	day;
	std::size_t	index[2];

	index[MONTH_INDEX] = date.find_first_of('-', 0);
	index[DAY_INDEX] = date.find_first_of('-', index[MONTH_INDEX] + 1);
	year = date.substr(0, index[MONTH_INDEX]);
	month = date.substr(index[MONTH_INDEX] + 1, index[DAY_INDEX] - index[MONTH_INDEX] - 1);
	day = date.substr(index[DAY_INDEX] + 1, date.length() - index[DAY_INDEX] - 1);

	t.tm_year = std::atoi(year.c_str()) - 1900;
	t.tm_mon = std::atoi(month.c_str()) - 1;
	t.tm_mday = std::atoi(day.c_str());
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1;
	timestamp = std::mktime(&t);
	return (timestamp);
}

static std::string	convertTimestampToString(std::time_t rawtime)
{
	std::string 		ret;
	struct tm			ts;
	std::ostringstream	temp;

	ts = *std::localtime(&rawtime);
	temp << (int)(ts.tm_year + 1900);
	temp << "-";
	if (ts.tm_mon + 1 < 10)
		temp << "0";
	temp << (int)(ts.tm_mon + 1);
	temp << "-";
	if (ts.tm_mday < 10)
		temp << "0";
	temp << (int)ts.tm_mday;
	ret = temp.str();
	return (ret);
}

static bool	isValidLine(std::string date, std::string value)
{
	if (!isValidDate(date))
		return (printErrorMessages("Invalid date -> " + date));
	if (!isValidValue(value))
		return (printErrorMessages("The value must be a number between 0 and 100"));
	return (true);
}

static bool	existFebruary29(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
			return (true);
		else
			if (year % 100 == 0 && year % 400 == 0)
				return (true);
	}
	return (false);
}

static bool	existDate(std::string year, std::string month, std::string day)
{
	int	intYear = std::atoi(year.c_str());
	int	intMonth = std::atoi(month.c_str());
	int	intDay = std::atoi(day.c_str());

	if (intMonth < 0 || intMonth > 12 || intDay < 0 || intMonth > 31)
		return (false);
	if (intMonth == 2 || intMonth == 4 || intMonth == 6 || intMonth == 8 || intMonth == 10)
		if (intDay > 30)
			return (false);
	if (intMonth == 2)
	{
		if (intDay > 29)
			return (false);
		if (intDay == 29)
			if (!existFebruary29(intYear))
				return (false);
	}
	return (true);
}

static bool	isValidDate(std::string date)
{
	std::string	year;
	std::string	month;
	std::string	day;
	std::size_t	index[2];

	if (date.empty())
		return (false);
	if (date.find_first_not_of("0123456789-", 0) != date.npos)
		return (false);
	index[MONTH_INDEX] = date.find_first_of('-', 0);
	index[DAY_INDEX] = date.find_first_of('-', index[MONTH_INDEX] + 1);
	year = date.substr(0, index[MONTH_INDEX]);
	month = date.substr(index[MONTH_INDEX] + 1, index[DAY_INDEX] - index[MONTH_INDEX] - 1);
	day = date.substr(index[DAY_INDEX] + 1, date.length() - index[DAY_INDEX] - 1);
	if (year.empty() || month.empty() || day.empty())
		return (false);
	if (!existDate(year, month, day))
		return (false);
	return (true);
}

static bool	isValidValue(std::string value)
{
	float	fValue;

	fValue = std::atof(value.c_str());
	if (fValue <= 0 || fValue > 1000)
		return (false);
	return (true);
}

static bool	printErrorMessages(std::string error)
{
	std::cerr << "Error: " << error << std::endl;
	return (false);
}
