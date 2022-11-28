#pragma once

#include <ClapTrap.hpp>

class ScavTrap: virtual public ClapTrap
{
    public:

        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    attack(const std::string &target);
        void    guardGate(void);

        int getEnergyPoints(void) const;

        ScavTrap &operator = (const ScavTrap &src);

        ScavTrap(const ScavTrap &src);
        ScavTrap(std::string name);
        ScavTrap();
        ~ScavTrap();
};
