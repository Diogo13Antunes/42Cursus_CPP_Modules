#include "head.hpp"

int main(int ac, char **av)
{
	Replacer	rpl;

	if (ac != 4)
	{
		Terminal::write("Error: Invalid number of arguments\n");
		Terminal::write("Correct Form: ./replacer [filename] [string 1] [string 2]\n");
		return (EXIT_FAILURE);
	}
	if (rpl.setFile(av[1]))
		return (EXIT_FAILURE);
	rpl.setString1(av[2]);
	rpl.setString2(av[3]);
	rpl.createNewFile();
	rpl.makeReplace();
	return (EXIT_SUCCESS);
}
