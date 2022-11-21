#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr_int)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPoint = (nbr_int * (int)(1<<fracBits));
}

Fixed::Fixed(const float nbr_float)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf((float)nbr_float * (float)(1<<fracBits));
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator= (const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixedPoint = f.fixedPoint;
	return (*this);
}

std::ostream &operator<< (std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
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

	result = ((float)fixedPoint / (float)(1<<fracBits));
	return (result);
}

int	Fixed::toInt(void) const
{
	int	result;

	// result = fixedPoint / (int)(1<<fracBits);
	result = fixedPoint >> fracBits;
	return (result);
}
