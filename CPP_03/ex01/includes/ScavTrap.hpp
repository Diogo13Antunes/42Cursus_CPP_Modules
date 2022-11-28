#pragma once

#include <ClapTrap.hpp>

class ScavTrap: public ClapTrap
{
    public:

        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    attack(const std::string &target);
        void    guardGate(void);

        ScavTrap &operator = (const ScavTrap &src);

        ScavTrap(const ScavTrap &src);
        ScavTrap(std::string name);
        ScavTrap();
        ~ScavTrap();
};
