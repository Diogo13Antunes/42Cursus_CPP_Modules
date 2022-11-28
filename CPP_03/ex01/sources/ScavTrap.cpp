#include <ScavTrap.hpp>

ScavTrap::ScavTrap():
	ClapTrap(), _name("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "Called ScavTrap default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name), _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "Called ScavTrap name constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src):
	ClapTrap()
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Called ScavTrap default destructor!" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void    ScavTrap::guardGate(void)
{
	std::cout << this->_name;
	std::cout << " entered in Gate Keeper mode.";
	std::cout << std::endl;
}
