#pragma once

#include <Animal.hpp>

class Dog: public Animal
{
    public:

        void    makeSound(void) const;

        Dog &operator = (const Dog &src);

        Dog(const Dog &src);
        Dog();
        ~Dog();

};
