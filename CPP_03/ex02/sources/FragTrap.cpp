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

void    FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap ";
	std::cout << _name;
	std::cout << " takes ";
	std::cout << amount;
	std::cout << " of damage!" << std::endl;
	_hitPoints = _hitPoints - amount;
}

void    FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points to be repaired!" << std::endl;
		return ;
	}
	std::cout << "FragTrap ";
	std::cout << _name;
	std::cout << " repaired ";
	std::cout << amount;
	std::cout << " hit points!" << std::endl;
	this->_hitPoints = _hitPoints + amount;
	this->_energyPoints -= 1;
}

void    FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap ";
	std::cout << _name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << ", causing ";
	std::cout << _attackDamage;
	std::cout << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}
