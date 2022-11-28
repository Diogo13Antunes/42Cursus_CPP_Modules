#pragma once

#include <ClapTrap.hpp>

class ScavTrap: virtual public ClapTrap
{
    public:
        void    guardGate(void);

        ScavTrap &operator = (const ScavTrap &src);

        int getEnergyPoints();

        ScavTrap(const ScavTrap &src);
        ScavTrap(std::string name);
        ScavTrap();
        ~ScavTrap();
};
