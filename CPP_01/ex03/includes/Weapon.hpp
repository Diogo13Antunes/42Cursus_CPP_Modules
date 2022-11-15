#pragma once

#include <string>

class Weapon
{
    public:
        void            setType(std::string newType);
        std::string     getType(void) const;

        Weapon(std::string type);
        ~Weapon();
    
    private:
        std::string type;
};
