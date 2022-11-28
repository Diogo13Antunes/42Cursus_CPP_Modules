#include <Cat.hpp>

Cat::Cat():
	Animal()
{
	this->_type = "Cat";
	std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(const Cat &src):
	Animal()
{
	*this = src;
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	this->_type = src._type;
	std::cout << "Cat Copy Assignment" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Default Destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat Sound" << std::endl;
}
