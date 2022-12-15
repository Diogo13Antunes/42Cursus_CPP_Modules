#include <Conversor.hpp>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments!" << std::endl;
		std::cout << "Usage: ./conversor [nbr_to_convert]" << std::endl;
		return (-1);
	}
	Conversor	gg;

	std::string value(av[1]);
	gg.convert(value);

	return (0);
}
