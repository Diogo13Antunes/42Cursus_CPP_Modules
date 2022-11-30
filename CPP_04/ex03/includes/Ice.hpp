#pragma once

#include <AMateria.hpp>

class Ice: public AMateria
{
    public:
        Ice         &operator=(const Ice &src);
    
        virtual AMateria    *clone(void) const;

        Ice(const Ice &src);
        Ice(void);
        virtual ~Ice(void);

    private:

};
