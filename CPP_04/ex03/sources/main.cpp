#include <Ice.hpp>
#include <Cure.hpp>
#include <Character.hpp>
#include <MateriaSource.hpp>

int	main(void)
{

	IMateriaSource	*oldsrc = new MateriaSource();
	AMateria* test = NULL;
	
	std::cout << "---------------------------------------------" << std::endl;
	
	oldsrc->learnMateria(test);
	test = new Ice();
	oldsrc->learnMateria(test);
	delete test;
	test = new Cure();
	oldsrc->learnMateria(test);
	delete test;
	test = new Ice();
	oldsrc->learnMateria(test);
	delete test;
	test = new Cure();
	oldsrc->learnMateria(test);
	delete test;
	test = new Cure();
	oldsrc->learnMateria(test);
	delete test;


	std::cout << "---------------------------------------------" << std::endl;

	IMateriaSource* src = new MateriaSource(*(MateriaSource*)oldsrc);

	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << "---------------------------------------------" << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("rainbow power");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "---------------------------------------------" << std::endl;

	ICharacter* bob = new Character("bob");
	ICharacter* charles = new Character(*(Character*)me);

	std::cout << "slot 0" << std::endl;
	charles->use(0, *bob);
	std::cout << "slot 1" << std::endl;
	charles->use(1, *bob);
	std::cout << "slot 2" << std::endl;
	charles->use(2, *bob);
	std::cout << "slot 3" << std::endl;
	charles->use(3, *bob);
	std::cout << "slot 4?" << std::endl;
	charles->use(4, *bob);

	delete bob;
	delete charles;
	delete me;
	delete src;
	delete oldsrc;
	return 0;
}
