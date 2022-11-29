#pragma once

#include <AAnimal.hpp>
#include <Brain.hpp>

class Dog: public AAnimal
{
    public:

        virtual void    makeSound(void) const;

        Dog &operator = (const Dog &src);

        Dog(const Dog &src);
        Dog();
        ~Dog();

    private:
        Brain   *_brain;
};
