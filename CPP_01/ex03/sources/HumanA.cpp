#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon w)
{
	setName(name);
	weapon = &w;
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

void    HumanA::attack(void) const
{
	std::cout << name << "attacks with their" << weapon.getType() << std::endl;
}
