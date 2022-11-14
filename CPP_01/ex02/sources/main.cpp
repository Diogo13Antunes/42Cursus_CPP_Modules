#include <iostream>
#include <string>

void	print(std::string *str, std::string var)
{
	std::cout << var << " | ";
	std::cout << str;
	std::cout << " | ";
	std::cout << *str;
	std::cout << std::endl;
}

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	print(&str, "STR        ");
	print(stringPTR, "stringPTR  ");
	print(&stringREF, "stringREF  ");
}
