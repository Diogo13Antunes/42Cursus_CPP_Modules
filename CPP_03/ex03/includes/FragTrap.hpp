#pragma once

#include <ClapTrap.hpp>

class FragTrap: virtual public ClapTrap
{
    public:

        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    attack(const std::string &target);

        int getAttackDamage(void) const;
        int getHitPoints(void) const;

        void    highFivesGuys(void);

        FragTrap &operator = (const FragTrap &src);

        FragTrap(const FragTrap &src);
        FragTrap(std::string name);
        FragTrap();
        ~FragTrap();

};
