#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	H_Comp;

	if (ac != 2)
	{
		std::cout << "Invalid number of args!" << std::endl;
		return (-1);
	}
	H_Comp.complain(av[1]);
}
