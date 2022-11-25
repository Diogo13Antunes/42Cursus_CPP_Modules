#include <ClapTrap.hpp>

int main(void)
{
	std::string	name = "Dummy";
	ClapTrap initial;
	ClapTrap dummy(name);

	std::cout << "\n--------- Attack ---------\n" << std::endl;
	
	initial.attack("Zane");

	std::cout << std::endl;

	dummy.attack("Zane");

	std::cout << "\n------ Take Damage -------\n" << std::endl;

	initial.takeDamage(1);

	std::cout << std::endl;
	
	dummy.takeDamage(1);
	
	std::cout << "\n------ Be Repaired -------\n" << std::endl;
	
	initial.beRepaired(1);
	
	std::cout << std::endl;

	dummy.beRepaired(1);


	return (0);
}
