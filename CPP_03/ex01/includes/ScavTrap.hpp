#pragma once

#include <ClapTrap.hpp>

class ScavTrap: public ClapTrap
{
    public:
        void    guardGate(void);

        ScavTrap &operator = (const ScavTrap &src);

        ScavTrap(const ScavTrap &src);
        ScavTrap(std::string name);
        ScavTrap();
        ~ScavTrap();
};
