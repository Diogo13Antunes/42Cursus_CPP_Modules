#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::~Weapon()
{

}

void    Weapon::setType(std::string newType)
{
	type = newType;
}

std::string    Weapon::getType(void) const
{
	return (type);
}
