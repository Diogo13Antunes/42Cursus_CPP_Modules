#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		BitcoinExchange	exchanger;
		return (0);
	}
	std::cerr << "Invalid Number of Arguments" << std::endl;
	return (1);
}
