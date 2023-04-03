#include <RPN.hpp>

static bool								isValidData(const char *str);
static void								eraseStringSpaces(std::string *str);
static bool								printErrorMsg(std::string error);
static bool								isNumber(char c);
static bool								isSignal(char c);

static int								calcResult(std::string src);

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
	(void)src;
	return (*this);
}

void	RPN::getData(const char *src)
{
	std::string	str;

	str = src;
	if (!isValidData(src))
		return ;
	eraseStringSpaces(&str);
	calcResult(str);
}

static bool	isValidData(const char *str)
{
	size_t	amountNumbers = 0;
	size_t	amountSignals = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		if (!isNumber(str[i]) && !isSignal(str[i]) && str[i] != ' ')
			return (printErrorMsg("Invalid elements in Argument"));
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (isNumber(str[i]))
			amountNumbers += 1;
		else if (isSignal(str[i]))
			amountSignals += 1;
	}
	if (amountSignals != amountNumbers - 1)
		return (printErrorMsg("Invalid number of signals and numbers"));
	return (true);
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

static int	calcResult(std::string src)
{
	std::stack<int>	data;
	int	result = 0;
	int	n1, n2;

	for (size_t i = 0; src[i]; i++)
	{
		if (isNumber(src[i]))
			data.push(src[i] - '0');
		else
		{
			if (data.size() < 2)
				return (printErrorMsg("Invalid Formatation"));
			n2 = data.top();
			data.pop();
			n1 = data.top();
			data.pop();
			if (src[i] == '/')
			{
				if (!n2)
					return (printErrorMsg("Impossible to devide by 0"));
				result = n1 / n2;
			}
			else if (src[i] == '*')
				result = n1 * n2;
			else if (src[i] == '+')
				result = n1 + n2;
			else
				result = n1 - n2;
			data.push(result);
		}
	}
	result = data.top();
	std::cout << result << std::endl;
	return (0);
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

static bool	printErrorMsg(std::string error)
{
	std::cerr << "Error: " << error << std::endl;
	return (false);
}
