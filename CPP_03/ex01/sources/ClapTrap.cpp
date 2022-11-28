#include <ClapTrap.hpp>

ClapTrap::ClapTrap():
	_name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Called ClapTrap default constructor!" << std::endl;
}

ClapTrap::ClapTrap(std::string &name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Called ClapTrap name constructor!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called ClapTrap default destructor!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &c)
{
	std::cout << "Called ClapTrap Copy constructor!" << std::endl;
	*this = c;
}

ClapTrap &ClapTrap::operator= (const ClapTrap &f)
{
	std::cout << "Copy ClapTrap assignment operator called" << std::endl;
	this->_name = f._name;
	this->_hitPoints = f._hitPoints;
	this->_attackDamage = f._attackDamage;
	this->_energyPoints = f._energyPoints;
	return (*this);
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap ";
	std::cout << _name;
	std::cout << " takes ";
	std::cout << amount;
	std::cout << " of damage!" << std::endl;
	_hitPoints = _hitPoints - amount;
	std::cout << "----- STATUS -----" << std::endl;
	std::cout << "Name          = " << this->_name << std::endl;
	std::cout << "Hit Points    = " << this->_hitPoints << std::endl;
	std::cout << "Energy Points = " << this->_energyPoints << std::endl;
	std::cout << "------------------" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap ";
	std::cout << _name;
	std::cout << " repaired ";
	std::cout << amount;
	std::cout << " hit points!" << std::endl;
	this->_hitPoints = _hitPoints + amount;
	this->_energyPoints -= 1;
	std::cout << "--------- STATUS ---------" << std::endl;
	std::cout << "Name          = " << this->_name << std::endl;
	std::cout << "Hit Points    = " << this->_hitPoints << std::endl;
	std::cout << "Energy Points = " << this->_energyPoints << std::endl;
	std::cout << "--------------------------" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap ";
	std::cout << _name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << ", causing ";
	std::cout << _attackDamage;
	std::cout << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	std::cout << "--------- STATUS ---------" << std::endl;
	std::cout << "Name          = " << this->_name << std::endl;
	std::cout << "Hit Points    = " << this->_hitPoints << std::endl;
	std::cout << "Energy Points = " << this->_energyPoints << std::endl;
	std::cout << "--------------------------" << std::endl;
}
