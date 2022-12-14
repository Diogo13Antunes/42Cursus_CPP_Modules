#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main()
{
	std::cout << "=======================================" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "=======================================" << std::endl;
	const Animal* i = new Cat();
	std::cout << "=======================================" << std::endl;
	const Animal* j = new Dog();
	std::cout << "=======================================" << std::endl;
	const Animal* s = new WrongCat();
	std::cout << "=======================================" << std::endl;
	
	std::cout << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << s->getType() << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << "=======================================" << std::endl;
	
	std::cout << std::endl;

	std::cout << "=======================================" << std::endl;
	i->makeSound();
	j->makeSound();
	s->makeSound();
	meta->makeSound();
	std::cout << "=======================================" << std::endl;


	std::cout << std::endl;

	std::cout << "=======================================" << std::endl;
	delete meta;
	delete i;
	delete j;
	delete s;
	std::cout << "=======================================" << std::endl;

	std::cout << std::endl;

	return (0);
}
