#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
    public:
        void            attack(void) const;
        void            setName(std::string n);
        std::string     getName(void) const;
        void            setWeapon(Weapon &newWeapon);
        Weapon          *getWeapon(void) const;
        HumanB(std::string name);
        ~HumanB();

    private:
        Weapon      *weapon;
        std::string name;
};
