#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const int nbr_int)
{
	fixedPoint = (nbr_int * (int)(1<<fracBits));
}

Fixed::Fixed(const float nbr_float)
{
	fixedPoint = roundf((float)nbr_float * (float)(1<<fracBits));
}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::~Fixed()
{

}

Fixed	&Fixed::operator+(const Fixed &f)
{
	this->fixedPoint += f.fixedPoint;
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &f)
{
	this->fixedPoint -= f.fixedPoint;
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &f)
{
	this->fixedPoint *= f.fixedPoint;
	return (*this);
}

Fixed	&Fixed::operator/(const Fixed &f)
{
	this->fixedPoint /= f.fixedPoint;
	return (*this);
}

int	Fixed::operator>(const Fixed &f)
{
	if (this->fixedPoint > f.fixedPoint)
		return (1);
	else
		return (0);
}

int	Fixed::operator<(const Fixed &f)
{
	if (this->fixedPoint < f.fixedPoint)
		return (1);
	else
		return (0);
}

int	Fixed::operator>=(const Fixed &f)
{
	if (this->fixedPoint >= f.fixedPoint)
		return (1);
	else
		return (0);
}

int	Fixed::operator<=(const Fixed &f)
{
	if (this->fixedPoint <= f.fixedPoint)
		return (1);
	else
		return (0);
}

int	Fixed::operator==(const Fixed &f)
{
	if (this->fixedPoint == f.fixedPoint)
		return (1);
	else
		return (0);
}

int	Fixed::operator!=(const Fixed &f)
{
	if (this->fixedPoint != f.fixedPoint)
		return (1);
	else
		return (0);
}

Fixed &Fixed::operator= (const Fixed &f)
{
	fixedPoint = f.fixedPoint;
	return (*this);
}

Fixed Fixed::operator++()
{
	++this->fixedPoint;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	this->fixedPoint++;
	return (temp);
}

Fixed Fixed::operator--()
{
	--this->fixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	this->fixedPoint--;
	return (temp);
}

std::ostream &operator<< (std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const
{
	return (fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
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

	result = fixedPoint >> fracBits;
	return (result);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.fixedPoint > f2.fixedPoint)
		return (f1);
	else
		return (f2);
}

Fixed const &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.fixedPoint > f2.fixedPoint)
		return (f1);
	else
		return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.fixedPoint > f2.fixedPoint)
		return (f2);
	else
		return (f1);
}

Fixed const &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.fixedPoint > f2.fixedPoint)
		return (f2);
	else
		return (f1);
}
