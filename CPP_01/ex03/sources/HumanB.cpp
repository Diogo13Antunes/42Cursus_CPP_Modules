#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	setName(name);
}

HumanB::~HumanB()
{

}

void	HumanB::setName(std::string n)
{
	name = n;
}

std::string	HumanB::getName(void) const
{
	return (name);
}

void	HumanB::setWeapon(Weapon *newWeapon)
{
	weapon = newWeapon;
}

Weapon	*HumanB::getWeapon(void) const
{
	return (weapon);
}

void    HumanB::attack(void) const
{
	std::cout << name;
	std::cout << "attacks with their";
	std::cout << weapon->getType() << std::endl;
}
