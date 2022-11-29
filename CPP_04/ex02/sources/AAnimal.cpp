#include <AAnimal.hpp>

AAnimal::AAnimal():
	_type("AAnimal_Type")
{
	std::cout << "AAnimal Default Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
	std::cout << "AAnimal Copy Constructor" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	this->_type = src._type;
	std::cout << "AAnimal Copy Assignment" << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Default Destructor" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
