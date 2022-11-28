#include <ScavTrap.hpp>

ScavTrap::ScavTrap(): ClapTrap()
{
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Called ScavTrap default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
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

void    ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap ";
	std::cout << _name;
	std::cout << " takes ";
	std::cout << amount;
	std::cout << " of damage!" << std::endl;
	_hitPoints = _hitPoints - amount;
}

void    ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points to be repaired!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap ";
	std::cout << _name;
	std::cout << " repaired ";
	std::cout << amount;
	std::cout << " hit points!" << std::endl;
	this->_hitPoints = _hitPoints + amount;
	this->_energyPoints -= 1;
}

void    ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap ";
	std::cout << _name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << ", causing ";
	std::cout << _attackDamage;
	std::cout << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}
