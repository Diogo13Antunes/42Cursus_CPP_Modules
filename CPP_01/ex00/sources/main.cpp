#include "Zombie.hpp"

int main()
{
	Zombie	*alocZombie;
	
	alocZombie = newZombie("alocZombie");
	randomChump("nonAlocZombie");
	std::cout << "end" << std::endl;
	delete alocZombie;
}
