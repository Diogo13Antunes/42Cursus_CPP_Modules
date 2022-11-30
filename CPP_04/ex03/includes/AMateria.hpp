#pragma once

#include <iostream>
#include <string>
#include <ICharacter.hpp>

class AMateria
{
    public:

        AMateria &operator = (const AMateria &src);

        AMateria(const AMateria &src);
        AMateria(const std::string &type);
        virtual ~AMateria(void);

        const std::string   &getType(void) const;
        virtual void        use(ICharacter &target);
        virtual AMateria    *clone(void) const = 0;

    protected:
        std::string _type;
        AMateria(void);

};
