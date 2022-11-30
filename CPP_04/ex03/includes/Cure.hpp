#pragma once

#include <AMateria.hpp>

class Cure: public AMateria
{
    public:
        Cure         &operator=(const Cure &src);
    
        virtual AMateria    *clone(void) const;

        Cure(const Cure &src);
        Cure(void);
        virtual ~Cure(void);

    private:

};
