#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		BitcoinExchange	btc;
		btc.exchanger(av[1]);
		return (0);
	}
	std::cerr << "Invalid Number of Arguments" << std::endl;
	return (1);
}
