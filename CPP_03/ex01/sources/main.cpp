#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

int main(void)
{
	std::string	name = "Dummy";
	ScavTrap	dummy(name);

	dummy.attack("FL4K");
	dummy.takeDamage(3);
	dummy.beRepaired(3);
	dummy.guardGate();
	for (int i = 0; i < 48; i++)
		dummy.beRepaired(1);
	dummy.attack("FL4K");
	return (0);
}
