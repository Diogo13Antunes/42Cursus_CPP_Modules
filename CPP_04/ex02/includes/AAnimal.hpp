#pragma once

#include <string>
#include <iostream>

class AAnimal
{
    public:

        virtual void    makeSound(void) const = 0;
        std::string     getType(void) const;

        AAnimal &operator = (const AAnimal &src);

        AAnimal(const AAnimal &src);
        AAnimal();
        virtual ~AAnimal();

    protected:
        std::string _type;
};
