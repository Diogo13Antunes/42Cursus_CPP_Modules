#include <WrongCat.hpp>

WrongCat::WrongCat():
	Animal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src):
	Animal()
{
	*this = src;
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	this->_type = src._type;
	std::cout << "WrongCat Copy Assignment" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Default Destructor" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat Sound" << std::endl;
}
