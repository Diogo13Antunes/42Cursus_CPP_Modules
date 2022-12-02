#pragma once

#include <AMateria.hpp>
#include <ICharacter.hpp>

class Cure: public AMateria
{
    public:

        Cure        &operator=(const Cure &src);

        virtual AMateria    *clone(void) const;
        void                use(ICharacter &target);

        Cure(const Cure &src);
        Cure(void);
        virtual ~Cure(void);

};
