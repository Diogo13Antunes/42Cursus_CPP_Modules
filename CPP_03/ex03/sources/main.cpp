#include <DiamondTrap.hpp>

int main(void)
{
	std::string	name = "Dummy";
	DiamondTrap	dummy(name);

	dummy.printStatus();
	dummy.attack("FL4K");
	dummy.printStatus();
	
	return (0);
}
