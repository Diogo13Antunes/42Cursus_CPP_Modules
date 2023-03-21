#include <RPN.hpp>

static void	eraseStringSpaces(std::string *str);
static std::list<std::string>	reorganizeStringToInfinNotation(const std::string *str);
static std::string	getSignals(const std::string *str);
static std::string	getNumbers(const std::string *str);

RPN::RPN(void)
{
	//Default RPN Constructor
}

RPN::RPN(const RPN &src)
{
	//RPN Copy Constructor
	*this = src;
}

RPN::~RPN(void)
{
	//Default RPN Destructor
}

RPN &RPN::operator=(const RPN &src)
{
	//RPN Copy Assignment Operator
	this->_data = src._data;
	return (*this);
}

void	RPN::getData(const char *src)
{
	std::string	str;

	std::list<std::string>::iterator	it;

	str = src;
	std::cout << "Input:       \'" << str << "\'" << std::endl;
	eraseStringSpaces(&str);
	std::cout << "No Spaces:   \'" << str << "\'" << std::endl;
	this->_data = reorganizeStringToInfinNotation(&str);
	std::cout << "Reorganized: \'";
	for (it = this->_data.begin(); it != this->_data.end(); it++)
		std::cout << it->data();
	std::cout << "\'" << std::endl;
}

static void	eraseStringSpaces(std::string *str)
{
	size_t	index = 0;

	while (1)
	{
		index = str->find_first_of(' ', index);
		if (index == str->npos)
			break;
		str->erase(index, 1);
	}
}

static std::list<std::string>	reorganizeStringToInfinNotation(const std::string *str)
{
	std::list<std::string>	infinNotation;
	std::string				nbrs;
	std::string				signals;
	std::string				temp;

	signals = getSignals(str);
	nbrs = getNumbers(str);
	std::cout << " ";
	for (size_t i = 0; i < signals.length(); i++)
		std::cout << signals[i] << " | ";
	std::cout << std::endl;
	std::cout << " ";
	for (size_t i = 0; i < nbrs.length(); i++)
		std::cout << nbrs[i] << " | ";
	std::cout << std::endl;

	for (size_t i = 0; i < nbrs.length(); i++)
	{
		temp = nbrs[i];
		infinNotation.push_back(temp);
		if (i < signals.length())
		{
			temp = signals[i];
			infinNotation.push_back(temp);
		}
	}
	return (infinNotation);
}

static bool	isSignal(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);	
	return (false);
}

static bool	isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static std::string	getSignals(const std::string *str)
{
	size_t		lastNbr;
	std::string	tempSignals;
	std::string	temp;

	(void)isNumber('a');
	lastNbr = (*str).find_last_not_of("+-*/");
	for (size_t i = lastNbr + 1; i < (*str).length(); i++)
		tempSignals += (*str)[i];
	for (int i = lastNbr; i >= 0; i--)
		if (isSignal((*str)[i]))
			tempSignals += (*str)[i];
	for (size_t i = 0; i < tempSignals.length() / 2; i++)
	{
		temp[0] = tempSignals[i];
		tempSignals[i] = tempSignals[tempSignals.length() - 1 - i];
		tempSignals[tempSignals.length() - 1 - i] = temp[0];
	}
	return (tempSignals);
}

static std::string	getNumbers(const std::string *str)
{
	std::string	numbers;

	for (int i = 0; (*str)[i]; i++)
	{
		if (isNumber((*str)[i]))
			numbers += (*str)[i];
	}
	return (numbers);
}
