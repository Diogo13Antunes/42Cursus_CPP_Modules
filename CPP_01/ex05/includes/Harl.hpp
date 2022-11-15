#pragma once

#include <iostream>
#include <string>

class Harl
{
    public:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

        void    complain(std::string level);

        Harl();
        ~Harl();
};
