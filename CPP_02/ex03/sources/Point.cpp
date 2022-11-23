#include <Point.hpp>

Point::Point():
	_x(0), _y(0) {}

Point::Point(const float x, const float y):
	_x(Fixed(x)), _y(Fixed(y)) {}

Point::~Point() {}

Point::Point(const Point &f)
{
	*this = f;
}

Point &Point::operator= (const Point &f)
{
	Fixed	*x = const_cast <Fixed *> (&this->_x);
	Fixed	*y = const_cast <Fixed *> (&this->_y);
	*x = f._x;
	*y = f._y;
	return (*this);
}

const Fixed	&Point::getXFixedPoint(void) const
{
	return (this->_x);
}

const Fixed	&Point::getYFixedPoint(void) const
{
	return (this->_y);
}
