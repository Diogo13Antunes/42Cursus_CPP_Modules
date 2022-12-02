#pragma once

#include <AMateria.hpp>
#include <ICharacter.hpp>

class Ice: public AMateria
{
    public:
        Ice         &operator=(const Ice &src);
        void        use(ICharacter &target);
    
        virtual AMateria    *clone(void) const;

        Ice(const Ice &src);
        Ice(void);
        virtual ~Ice(void);

    private:

};
