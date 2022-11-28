#include <ClapTrap.hpp>

ClapTrap::ClapTrap():
	_name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Called default constructor!" << std::endl;
}

ClapTrap::ClapTrap(std::string &name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Called name constructor!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called default destructor!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &c)
{
	std::cout << "Called Copy constructor!" << std::endl;
	*this = c;
}

ClapTrap &ClapTrap::operator= (const ClapTrap &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = f._name;
	_hitPoints = f._hitPoints;
	_attackDamage = f._attackDamage;
	_energyPoints = f._energyPoints;
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
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points to be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap ";
	std::cout << _name;
	std::cout << " repaired ";
	std::cout << amount;
	std::cout << " hit points!" << std::endl;
	this->_hitPoints = _hitPoints + amount;
	this->_energyPoints -= 1;
}

void    ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enought energy points to attack!" << std::endl;
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
}

void	ClapTrap::printStatus(void) const
{
	std::cout << "--------- STATUS ---------" << std::endl;
	std::cout << "Name          = " << this->_name << std::endl;
	std::cout << "Hit Points    = " << this->_hitPoints << std::endl;
	std::cout << "Energy Points = " << this->_energyPoints << std::endl;
	std::cout << "Damage Points = " << this->_attackDamage << std::endl;
	std::cout << "--------------------------" << std::endl;
}
