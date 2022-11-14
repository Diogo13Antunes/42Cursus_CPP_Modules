#include "Zombie.hpp"

int main()
{
	Zombie	*horde;

	horde = zombieHorde(10, "Juvenal");
	delete [] horde;
}
