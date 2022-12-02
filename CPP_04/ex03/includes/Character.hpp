#pragma once

#include <ICharacter.hpp>

#define NBR_SLOTS 4

class Character: public ICharacter
{
    public:

        const std::string   &getName(void) const;
        void                equip(AMateria *m);
        void                unequip(int idx);
        void                use(int idx, ICharacter &target);

        void                showInventory(void) const;

        Character &operator=(const Character &src);

        Character(const std::string &name);
        Character(const Character &src);
        Character(void);
        ~Character(void);

    private:
        std::string _name;
        AMateria    *_inventory[NBR_SLOTS];
        int         _nbrMaterias;
};
