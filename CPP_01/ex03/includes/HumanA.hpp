#pragma once

#include "Weapon.hpp"
#include <string>

class HumanA
{
    public:
        void            attack(void) const;
        void            setName(std::string n);
        std::string     getName(void) const;
        HumanA();
        ~HumanA();

    private:
        Weapon      *weapon;
        std::string name;
};
