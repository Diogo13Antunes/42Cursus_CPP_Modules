#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
    public:
        void            attack(void) const;
        void            setName(std::string n);
        std::string     getName(void) const;
        void            setWeapon(Weapon *newWeapon);
        Weapon          *getWeapon(void) const;
        HumanA(std::string name, Weapon w);
        ~HumanA();

    private:
        Weapon      *weapon;
        std::string name;
};
