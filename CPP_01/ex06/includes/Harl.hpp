#pragma once

#include <iostream>
#include <string>

#define COMPLAIN_DEBUG      "DEBUG"
#define COMPLAIN_INFO       "INFO"
#define COMPLAIN_WARNING    "WARNING"
#define COMPLAIN_ERROR      "ERROR"

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
        int     getLevel(std::string level);
        void     printBefores(int index);
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

        t_complains list[NBR_COMPLAINS];
};
