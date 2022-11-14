#pragma once

#include <iostream>
#include <string>

// Defenition of Zombie Class
class Zombie
{
    public:
		void		setZombieName(std::string n);
		std::string	getZombieName(void) const;
		void		announce(void);

		Zombie(void);
		~Zombie(void);

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );
