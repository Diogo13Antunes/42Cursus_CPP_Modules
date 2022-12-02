#include <AMateria.hpp>
#include <ICharacter.hpp>


AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor" << std::endl;
}

AMateria::AMateria(const std::string &type): _type(type)
{
	std::cout << "AMateria Type Constructor" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default Destructor" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria &AMateria::operator = (const AMateria &src)
{
	this->_type = src._type;
	return (*this);
}

const std::string	&AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << " used an Materia" << std::endl;
}

AMateria *AMateria::clone(void) const
{
	AMateria *newMateria = NULL;
	return (newMateria);
}
