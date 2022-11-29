#pragma once

#include <string>
#include <iostream>

class Animal
{
    public:

        virtual void    makeSound(void) const;
        std::string     getType(void) const;

        Animal &operator = (const Animal &src);

        Animal(const Animal &src);
        Animal();
        virtual ~Animal();

    protected:
        std::string _type;

};
