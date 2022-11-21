#pragma once

#include <iostream>

class Fixed
{
    public:
        int getRawBits(void) const;
        void setRawBits(int const raw);

        Fixed &operator = (const Fixed &f);
        Fixed(const Fixed &f);
        Fixed();
        ~Fixed();

    private:
        int                 fixedPoint;
        static const int    fracBits = 8;
};
