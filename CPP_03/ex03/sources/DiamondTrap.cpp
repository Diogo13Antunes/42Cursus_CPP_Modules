#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string &name):
	ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	ScavTrap	tempScavTrap;

	this->_name = name;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	this->_energyPoints = tempScavTrap.getEnergyPoints();
	std::cout << "Called DiamondTrap name constructor!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void)
{
	std::cout << "==========================================" << std::endl;
	std::cout << "Hello I have 2 names: " << std::endl;
	std::cout << "Fisrt Name  = " << this->_name << std::endl;
	std::cout << "Second Name = " << ClapTrap::_name << std::endl;
	std::cout << "==========================================" << std::endl;
}
