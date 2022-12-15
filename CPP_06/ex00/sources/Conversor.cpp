#include <Conversor.hpp>

#define ERROR_INPUT_MSG "The value must be an CHAR, INT, FLOAT or DOUBLE"

Conversor::Conversor()
{
	//Default Conversor Constructor
}

Conversor::Conversor(const Conversor &src)
{
	//Conversor Copy Constructor
	(void)src;
}

Conversor::~Conversor()
{
	//Default Conversor Destructor
}

Conversor &Conversor::operator=(const Conversor &src)
{
	(void)src;
	return (*this);
}

void	Conversor::convert(std::string value)
{
	if (isEdgeCase(value))
	{
		edgeCasesConvertion(value);
		return ;
	}
	if (!checkInput(value))
	{
		std::cout << ERROR_INPUT_MSG << std::endl;
		return ;
	}
	if (value.find_last_of('f') == (value.length() - 1) && value.length() != 1)
		value.erase(value.length() - 1);
	charConvertion(value);
	intConvertion(value);
	floatConvertion(value);
	doubleConvertion(value);
	return ;
}

bool	Conversor::checkInput(std::string value) const
{
	if (value.find_first_of("0123456789+-") == 0 && value.find_first_not_of("0123456789+-f.") == value.npos)
	{
		if (value.find_first_of('f') != value.npos
			&& (value.find_first_of('f') != value.length() - 1
			|| (value.find_first_of('f') == value.length() - 1 && value.find_first_of('.') == value.npos)))
			return (false);
		else if (value.find_last_of("-+") != 0 && value.find_last_of("-+") != value.npos)
			return (false);
		else if (value.find_first_of('.') == 0
				|| value.find_last_of('.') == value.length() - 1
				|| value.find_first_of('.') != value.find_last_of('.')
				|| (value.find_last_of("-+") == 0 && value.find_first_of('.') == 1)
				|| (value.find_first_of('f') == value.length() - 1 && value.find_last_of('.') == value.length() - 2))
			return (false);	
	}
	else if (value[1] != '\0')
		return (false);
	return (true);
}

bool	Conversor::isEdgeCase(std::string value)
{
	if (value == "-inf" || value == "+inf" || value == "-inff" || value == "+inff" || value == "nan" || value == "nanf")
		return (true);
	return (false);
}

void	Conversor::charConvertion(std::string value)
{
	std::stringstream s;
	int value_int;

	if (value.length() != 1 || value.find_first_not_of("0123456789") == value.npos)
	{
		s << value;
		s >> value_int;
	}
	else
		value_int = static_cast<int>(value[0]);
	std::cout << "char: ";
	if (value_int < 0 || value_int > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if ((value_int >= 0 && value_int < 32) || value_int == 127)
	{
		std::cout << "Non displayable"<< std::endl;
		return ;
	}
	std::cout << "\'" << static_cast<char>(value_int) << "\'" << std::endl;
}

void	Conversor::intConvertion(std::string value)
{
	std::stringstream s;
	double value_double;

	if (value.length() != 1)
	{
		s << value;
		s >> value_double;
	}
	else
		value_double = static_cast<double>(value[0]);
	std::cout << "int: ";
	if (value_double > std::numeric_limits<int>::max() || value_double < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value_double) << std::endl;
}

void	Conversor::floatConvertion(std::string value)
{
	std::stringstream s;
	float value_float;

	if (value.length() != 1)
	{
		s << value;
		s >> value_float;
	}
	else
		value_float = static_cast<float>(value[0]);
	std::cout << "float: ";
	if (value.find_first_of(".") == value.npos)
		std::cout << std::fixed << std::setprecision(1) << value_float << 'f' << std::endl;
	else
		std::cout << value_float << 'f' << std::endl;
}

void	Conversor::doubleConvertion(std::string value)
{
	std::stringstream s;
	double value_double;

	if (value.length() != 1)
	{
		s << value;
		s >> value_double;
	}
	else
		value_double = static_cast<double>(value[0]);
	std::cout << "double: ";
	std::cout << value_double << std::endl;
}

void	Conversor::edgeCasesConvertion(std::string value)
{
	if (value == "-inf" || value == "+inf" || value == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
	else if (value == "-inff" || value == "+inff" || value == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << value << std::endl;
		value.erase(value.length() - 1);
		std::cout << "double: " << value << std::endl;
	}
	return ;
}
