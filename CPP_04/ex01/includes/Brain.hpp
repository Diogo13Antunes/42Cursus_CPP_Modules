#pragma once

#include <string>
#include <iostream>

#define NBR_IDEAS 100

class Brain
{
    public:

        Brain &operator = (const Brain &src);

        Brain(const Brain &src);
        Brain();
        ~Brain();

    private:
        std::string _ideas[NBR_IDEAS];

};
