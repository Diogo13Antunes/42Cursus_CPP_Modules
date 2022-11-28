#include <FragTrap.hpp>

int main(void)
{
	std::string	name = "Dummy";
	FragTrap	dummy(name);

	dummy.attack("FL4K");
	dummy.takeDamage(3);
	dummy.beRepaired(3);
	dummy.highFivesGuys();
	for (int i = 0; i < 98; i++)
		dummy.beRepaired(1);
	dummy.attack("FL4K");
	return (0);
}
