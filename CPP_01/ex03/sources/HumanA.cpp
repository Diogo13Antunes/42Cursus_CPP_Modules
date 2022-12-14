#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w)
{
	setName(name);
	setWeapon(w);
}

HumanA::~HumanA()
{

}

void	HumanA::setName(std::string n)
{
	name = n;
}

std::string	HumanA::getName(void) const
{
	return (name);
}

void	HumanA::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

Weapon	*HumanA::getWeapon(void) const
{
	return (weapon);
}

void    HumanA::attack(void) const
{
	Weapon		*actualWeapon = getWeapon();
	std::string	weaponType = actualWeapon->getType();

	std::cout << name;
	std::cout << "attacks with their";
	std::cout << weaponType << std::endl;
}
