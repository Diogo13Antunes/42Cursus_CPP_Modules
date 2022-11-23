#pragma once

#include <Fixed.hpp>

class Point
{
    public:
        const Fixed &getXFixedPoint(void) const;
        const Fixed &getYFixedPoint(void) const;

        Point(const Point &f);
        Point(const float x, const float y);
        Point();
        ~Point();

        Point &operator= (const Point &f);

    private:
        const Fixed     _x;
        const Fixed     _y;

};
