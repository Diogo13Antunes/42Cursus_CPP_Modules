#include <Cure.hpp>

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure Default Constructor" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure Default Destructor" << std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout << "Cure Copy Constructor" << std::endl;
	*this = src;
}

Cure &Cure::operator=(const Cure &src)
{
	std::cout << "Cure Copy Assignment" << std::endl;
	this->_type = src._type;
	return (*this);
}

AMateria *Cure::clone(void) const
{
	AMateria *result = new Cure();

	return (result);
}
