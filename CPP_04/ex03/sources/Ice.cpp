#include <Ice.hpp>

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice Default Constructor" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice Default Destructor" << std::endl;
}

Ice::Ice(const Ice &src)
{
	std::cout << "Ice Copy Constructor" << std::endl;
	*this = src;
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Ice Copy Assignment" << std::endl;
	this->_type = src._type;
	return (*this);
}

AMateria *Ice::clone(void) const
{
	AMateria *result = new Ice();

	return (result);
}
