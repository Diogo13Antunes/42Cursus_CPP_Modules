#pragma once

#include <ICharacter.hpp>
#include <AMateria.hpp>

#define NBR_SLOTS 4

class Character: public ICharacter
{
    public:


        Character(Character &c);
        Character(void);
        virtual ~Character(void);

    private:
        AMateria    *inventory[NBR_SLOTS];
};
