#include <Ice.hpp>
#include <Cure.hpp>

int main()
{
	
	std::cout << std::endl;
	
	AMateria *x = new Ice();
	AMateria *y = new Cure();
	AMateria *nx;
	AMateria *ny;

	std::cout << std::endl;

	std::cout << "====================================" << std::endl;
	std::cout << std::endl;
	std::cout << "My X Type: " << x->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "My Y Type: " << y->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << std::endl;

	std::cout << "====================================" << std::endl;
	std::cout << std::endl;
	nx = x->clone();
	std::cout << std::endl;
	ny = y->clone();
	std::cout << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << std::endl;

	delete x;
	delete y;
	delete nx;
	delete ny;

	std::cout << std::endl;

}
