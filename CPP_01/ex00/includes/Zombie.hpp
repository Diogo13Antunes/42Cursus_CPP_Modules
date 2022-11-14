#pragma once

// Includes
#include <iostream>
#include <string>

// Defenition of Zombie Class
class Zombie
{
    public:
		void		setZombieName(std::string zombieName);
		std::string	getZombieName(void) const;
		void		announce(void);

		Zombie(std::string name);
		~Zombie();

	private:
		std::string name;
};

// Functions to create Zombies
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);