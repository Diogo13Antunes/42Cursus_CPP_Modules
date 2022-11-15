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

void	HumanB::setWeapon(Weapon newWeapon)
{
	weapon = &newWeapon;
}

void    HumanB::attack(void) const
{
	std::cout << name << "attacks with their" << weapon.getType() << std::endl;
}
