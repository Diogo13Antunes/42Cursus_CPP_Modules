#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	setZombieName(name);
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << getZombieName() << ":";
	std::cout << "Died" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << getZombieName() << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setZombieName(std::string zombieName)
{
	name = zombieName;
}

std::string	Zombie::getZombieName(void) const
{
	return (name);
}
