#include <iter.hpp>

void	incrementerInt(const int &nbr)
{
	int nbrPlus = nbr + 1;
	std::cout << "[" << nbrPlus << "] ";
}

void	incrementerChar(const char &c)
{
	char charPlus = c + 1;
	std::cout << "[" << charPlus << "] ";
}

int main()
{
	int intArray[] = {1,2,3,4,5,6,7,8,9,10};
	size_t intArrayLen = 10;
	char charArray[] = {'a','b','c','d','e','f','g','h','i','j'};
	size_t charArrayLen = 10;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Initial Int Array" << std::endl;
	for (size_t i = 0; i < intArrayLen; i++)
		std::cout << "[" << intArray[i] << "] ";
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "\n----------------------------------------" << std::endl;
	std::cout << "Iter Int Array" << std::endl;
	iter<int>(intArray, intArrayLen, incrementerInt);
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "\n----------------------------------------" << std::endl;
	std::cout << "Initial Char Array" << std::endl;
	for (size_t i = 0; i < charArrayLen; i++)
		std::cout << "[" << charArray[i] << "] ";
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "\n----------------------------------------" << std::endl;
	std::cout << "Iter Char Array" << std::endl;
	iter<char>(charArray, charArrayLen, incrementerChar);
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}
