#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr_int)
{
	fixedPoint = (nbr_int * (int)(1<<fracBits));
}

Fixed::Fixed(const float nbr_float)
{
	fixedPoint = (nbr_float * (float)(1<<fracBits));
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = f.getRawBits();
}

Fixed &Fixed::operator= (const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixedPoint = f.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint = raw;
}

float   Fixed::toFloat( void ) const
{
	float	result;

	result = fixedPoint / (float)(1<<fracBits);
	return (result);
}

int	Fixed::toInt(void) const
{
	float	result;

	result = fixedPoint / (int)(1<<fracBits);
	return (result);
}
