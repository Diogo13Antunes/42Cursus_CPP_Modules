#include <Animal.hpp>

Animal::Animal():
	_type("Animal_Type")
{
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal Copy Constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	this->_type = src._type;
	std::cout << "Animal Copy Assignment" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Default Destructor" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Make Animal sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
