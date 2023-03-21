#include <RPN.hpp>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN Rpn;
		Rpn.getData(av[1]);
		return (0);
	}
	std::cerr << "Invalid number of Arguments" << std::endl;
	return (1);
}
