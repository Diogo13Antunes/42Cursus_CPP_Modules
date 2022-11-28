#pragma once

#include <ClapTrap.hpp>

class FragTrap: public ClapTrap
{
    public:

        void    highFivesGuys(void);

        FragTrap &operator = (const FragTrap &src);

        FragTrap(const FragTrap &src);
        FragTrap(std::string name);
        FragTrap();
        ~FragTrap();

};
