#pragma once

#include <Animal.hpp>

class WrongCat: public Animal
{
    public:

        void    makeSound(void) const;

        WrongCat &operator = (const WrongCat &src);

        WrongCat(const WrongCat &src);
        WrongCat();
        ~WrongCat();

};
