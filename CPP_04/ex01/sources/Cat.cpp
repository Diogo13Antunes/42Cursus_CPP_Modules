#include <Cat.hpp>

Cat::Cat():
	Animal()
{
	this->_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(const Cat &src):
	Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	*this = src;
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	std::cout << "Cat Copy Assignment" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Default Destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat Sound" << std::endl;
}
