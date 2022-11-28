#pragma once

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>
#include <FragTrap.hpp>

class DiamondTrap: public ScavTrap, public FragTrap
{
    public:

        void    whoAmI(void);
        void    attack(const std::string &target);

        DiamondTrap &operator = (const DiamondTrap &src);

        DiamondTrap(std::string &name);
        DiamondTrap(DiamondTrap &c);
        DiamondTrap();
        ~DiamondTrap();

    private:
        std::string _name;
};
