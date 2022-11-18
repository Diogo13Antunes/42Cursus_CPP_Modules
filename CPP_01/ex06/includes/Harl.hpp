#pragma once

#include <iostream>
#include <string>

#define NBR_COMPLAINS   4

class Harl;

typedef struct s_complains
{
    std::string complain;
    void        (Harl::*act)(void);
}               t_complains;

class Harl
{
    public:

        void    complain(std::string level);

        Harl(void);
        ~Harl(void);

    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

        t_complains list[NBR_COMPLAINS];
};
