#include <Dog.hpp>

Dog::Dog():
	AAnimal()
{
	this->_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog(const Dog &src):
	AAnimal()
{
	*this = src;
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	this->_type = src._type;
	std::cout << "Dog Copy Assignment" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Default Destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog Sound" << std::endl;
}
