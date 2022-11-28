#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Called FragTrap default constructor!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Called FragTrap name constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap()
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "Called FragTrap default destructor!" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void    FragTrap::highFivesGuys(void)
{
	std::cout << "Give me a Hight Five" << std::endl;
}
