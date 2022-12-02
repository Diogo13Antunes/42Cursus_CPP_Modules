#pragma once

#include <IMateriaSource.hpp>
#include <AMateria.hpp>

#define NBR_MATERIAS 4

class MateriaSource: public IMateriaSource
{
    public:

        AMateria    *createMateria(const std::string &type);
        void        learnMateria(AMateria *newMat);

        void        printLearnedMaterias(void) const;

        MateriaSource &operator=(const MateriaSource &src);

        MateriaSource(const MateriaSource &src);
        MateriaSource();
        ~MateriaSource();

    private:
        AMateria    *learnedMaterias[NBR_MATERIAS];
};
