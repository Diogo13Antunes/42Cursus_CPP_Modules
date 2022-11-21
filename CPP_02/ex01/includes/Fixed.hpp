#pragma once

#include <iostream>

class Fixed
{
    public:
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat( void ) const;
        int     toInt(void) const;

        Fixed &operator = (const Fixed &f);
        Fixed(const Fixed &f);
        Fixed(const int nbr_int);
        Fixed(const float nbr_float);
        Fixed();
        ~Fixed();

    private:
        int                 fixedPoint;
        static const int    fracBits = 8;
};
