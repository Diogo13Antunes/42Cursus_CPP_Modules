#include <ScavTrap.hpp>

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name), _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{}

void    ScavTrap::guardGate(void)
{
	std::cout << this->_name;
	std::cout << " entered in Gate Keeper mode.";
	std::cout << std::endl;
}
