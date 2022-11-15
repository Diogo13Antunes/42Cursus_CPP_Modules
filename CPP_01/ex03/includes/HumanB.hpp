#pragma once

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        void            attack(void) const;
        void            setName(std::string n);
        std::string     getName(void) const;
        HumanB();
        ~HumanB();

    private:
        Weapon      *weapon;
        std::string name;
};
