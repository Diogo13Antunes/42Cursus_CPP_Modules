#include <BitcoinExchange.hpp>

#define	MONTH_INDEX	0
#define	DAY_INDEX	1

static bool	isValidDate(std::string date);

BitcoinExchange::BitcoinExchange(void)
{
	this->dataBaseFileName = "data.csv";
	setDataBase(this->dataBaseFileName.c_str());
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	//BitcoinExchange Copy Constructor
	(void)src;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//Default BitcoinExchange Destructor
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	//BitcoinExchange Copy Assignment Operator
	(void)src;
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
	isValidDate("2023-03-17");
}

void	BitcoinExchange::exchanger(char *fileName)
{
	std::fstream	file;
	std::string		tempString;

	file.open(fileName, std::ios::in);
	std::getline(file, tempString);
	tempString.clear();
	
}

static bool	isValidDate(std::string date)
{
	std::string	year;
	std::string	month;
	std::string	day;
	std::size_t	index[2];

	printf("%s\n", date.c_str());
	if (date.empty())
		return (false);
	if (date.find_first_not_of("0123456789-", 0) != date.npos)
		return (false);
	index[MONTH_INDEX] = date.find_first_of('-', 0);
	index[DAY_INDEX] = date.find_first_of('-', index[MONTH_INDEX] + 1);
	year = date.substr(0, index[MONTH_INDEX]);
	month = date.substr(index[MONTH_INDEX] + 1, index[DAY_INDEX] - index[MONTH_INDEX] - 1);
	day = date.substr(index[DAY_INDEX] + 1, date.length() - index[DAY_INDEX] - 1);
	if (month.length() > 2 || day.length() > 2)
		return (false);
	if (std::stoi(month) > 12 || std::stoi(day) > 31)
		return (false);
	return (true);
}
