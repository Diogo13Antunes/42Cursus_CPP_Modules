#pragma once

#include <Animal.hpp>

class Cat: public Animal
{
    public:

        void    makeSound(void) const;

        Cat &operator = (const Cat &src);

        Cat(const Cat &src);
        Cat();
        ~Cat();

};
