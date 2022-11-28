#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
    public:

        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    attack(const std::string &target);
        
        ClapTrap &operator = (const ClapTrap &f);

        ClapTrap(std::string &name);
        ClapTrap(ClapTrap &c);
        ClapTrap();
        ~ClapTrap();

    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;

};
