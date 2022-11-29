#pragma once

#include <AAnimal.hpp>
#include <Brain.hpp>

class Cat: public AAnimal
{
    public:

        virtual void    makeSound(void) const;

        Cat &operator = (const Cat &src);

        Cat(const Cat &src);
        Cat();
        ~Cat();

    private:
        Brain   *_brain;
};
