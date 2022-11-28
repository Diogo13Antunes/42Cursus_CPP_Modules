#pragma once

#include <ClapTrap.hpp>

class FragTrap: virtual public ClapTrap
{
    public:

        void    highFivesGuys(void);

        FragTrap &operator = (const FragTrap &src);

        int getHitPoints(void) const;
        int getAttackDamage(void) const;

        FragTrap(const FragTrap &src);
        FragTrap(std::string name);
        FragTrap();
        ~FragTrap();


};
