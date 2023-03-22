#include <RPN.hpp>

static bool								isValidData(const char *str);
static void								eraseStringSpaces(std::string *str);
static std::list<std::string>			reorganizeStringToInfinNotation(const std::string *str);
static bool								printErrorMsg(std::string error);
static std::string						getSignals(const std::string *str);
static std::string						getNumbers(const std::string *str);
static bool								isNumber(char c);
static bool								isSignal(char c);


static int								stoi(std::string str);
static std::string						itos(int value);

static std::list<std::string>::iterator	existDivOrMult(std::list<std::string> *data);
static std::list<std::string>::iterator	existPlusOrSub(std::list<std::string> *data);
static bool								makeOperation(std::list<std::string> *data, std::list<std::string>::iterator *it);

void									calculateResult(std::list<std::string> *data);

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

	str = src;
	if (!isValidData(src))
		return ;
	eraseStringSpaces(&str);
	this->_data = reorganizeStringToInfinNotation(&str);
	calculateResult(&(this->_data));
}

void	calculateResult(std::list<std::string> *data)
{
	std::list<std::string>::iterator it;

	while (data->size() > 1)
	{
		it = existDivOrMult(data);
		if (it != data->end())
		{
			if (!makeOperation(data, &it))
				return ;
		}
		else
		{
			it = existPlusOrSub(data);
			if (!makeOperation(data, &it))
				return ;
		}
	}
	std::cout << data->begin()->data() << std::endl;
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

static std::list<std::string>	reorganizeStringToInfinNotation(const std::string *str)
{
	std::list<std::string>	infinNotation;
	std::string				nbrs;
	std::string				signals;
	std::string				temp;

	signals = getSignals(str);
	nbrs = getNumbers(str);
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

static std::string	invertString(std::string str)
{
	std::string	result;

	for (int i = str.length() - 1; i >= 0; i--)
		result += str[i];
	return (result);
}

static std::string	getSignals(const std::string *str)
{
	size_t		index = 0;
	std::string	signals;
	std::string	temp;

	while (index < str->length())
	{
		index = str->find_first_of("+-*/", index);
		while (isSignal(str->c_str()[index]))
			temp += (*str)[index++];
		signals += invertString(temp);
		temp.clear();
	}
	return (signals);
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

static bool	printErrorMsg(std::string error)
{
	std::cerr << "Error: " << error << std::endl;
	return (false);
}

static std::list<std::string>::iterator	existDivOrMult(std::list<std::string> *data)
{
	std::list<std::string>::iterator it;

	for (it = data->begin(); it != data->end(); it++)
	{
		if (!it->compare("*") || !it->compare("/"))
			return (it);
	}
	it = data->end();
	return (it);
}

static std::list<std::string>::iterator	existPlusOrSub(std::list<std::string> *data)
{
	std::list<std::string>::iterator it;

	for (it = data->begin(); it != data->end(); it++)
	{
		if (!it->compare("+") || !it->compare("-"))
			return (it);
	}
	it = data->end();
	return (it);
}

static bool	makeOperation(std::list<std::string> *data, std::list<std::string>::iterator *it)
{
	std::list<std::string>::iterator tempIt;
	std::list<std::string>::iterator n1;
	std::list<std::string>::iterator n2;
	std::string	signal;
	int			nbr1;
	int			nbr2;
	int			result;

	tempIt = *it;
	n1 = tempIt;
	n2 = tempIt;
	--n1;
	++n2;
	signal = tempIt->data();
	nbr1 = stoi((n1)->data());
	nbr2 = stoi((n2)->data());
	if (!signal.compare("/"))
	{
		if (!nbr2)
			return (printErrorMsg("Impossible to devide by 0"));
		result = nbr1 / nbr2;
	}
	else if (!signal.compare("*"))
		result = nbr1 * nbr2;
	else if (!signal.compare("+"))
		result = nbr1 + nbr2;
	else
		result = nbr1 - nbr2;
	(*data).erase(n1);
	(*data).erase(n2);
	(*data).insert(tempIt, itos(result));
	(*data).erase(tempIt);
	return (true);
}

static std::string	itos(int value)
{
	std::stringstream str;
	std::string	result;

	str << value;
	str >> result;
	return (result);
}

static int	stoi(std::string str)
{
	std::stringstream integer;
	int	result;

	integer << str;
	integer >> result;
	return (result);
}
