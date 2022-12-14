#include <MateriaSource.hpp>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < NBR_MATERIAS; i++)
		learnedMaterias[i] = NULL;
	std::cout << "MateriaSource Default Constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < NBR_MATERIAS; i++)
		this->learnedMaterias[i] = NULL;
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);
	for (int i = 0; i < NBR_MATERIAS; i++)
	{
		if (this->learnedMaterias[i] != NULL)
			delete this->learnedMaterias[i];
		if (src.learnedMaterias[i])
			this->learnedMaterias[i] = src.learnedMaterias[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Default Destructor" << std::endl;
	for (int i = 0; i < NBR_MATERIAS; i++)
	{
		if (this->learnedMaterias[i])
			delete this->learnedMaterias[i];
	}
}

void	MateriaSource::learnMateria(AMateria *newMat)
{
	if (!newMat)
		return ;
	for (int i = 0; i < NBR_MATERIAS; i++)
	{
		if (!this->learnedMaterias[i] && newMat)
		{
			this->learnedMaterias[i] = newMat->clone();
			std::cout << "Materia learned successfully" << std::endl;
			return ;
		}
	}
	std::cout << "You cannot learn more Materias" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	AMateria	*newMateria;

	newMateria = NULL;
	for (int i = 0; i < NBR_MATERIAS; i++)
	{
		if (this->learnedMaterias[i])
		{
			if (this->learnedMaterias[i]->getType().compare(type) == 0)
			{
				newMateria = this->learnedMaterias[i]->clone();
				break ;
			}
		}
	}
	if (!newMateria)
		std::cout << "Materia type is Unknown" << std::endl;
	else
		std::cout << "Materia type created successfully" << std::endl;
	return (newMateria);
}

void	MateriaSource::printLearnedMaterias(void) const
{
	std::cout << "<<<<<<<<<<<<<<<<<<<<->>>>>>>>>>>>>>>>>>>>" << std::endl;
	for (int i = 0; i < NBR_MATERIAS; i++)
	{
		if (this->learnedMaterias[i])
			std::cout << this->learnedMaterias[i]->getType() << std::endl;
		else
			std::cout << "Empty Slot" << std::endl;
	}
	std::cout << "<<<<<<<<<<<<<<<<<<<<->>>>>>>>>>>>>>>>>>>>" << std::endl;
}
