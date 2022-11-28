#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string &name):
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	ScavTrap	tempScavTrap;

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
