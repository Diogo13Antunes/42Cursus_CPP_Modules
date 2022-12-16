#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int main()
{
	srand (time(NULL));

	std::cout << "------------------ GENERATE POINTER ------------------" << std::endl;
	Base	*base1 = generate();
	Base	*base2 = generate();
	Base	*base3 = generate();
	std::cout << "------------------------------------------------------\n" << std::endl;

	std::cout << "--------------- IDENTIFY POINTER CALLS ---------------" << std::endl;
	identify(base1);
	identify(base2);
	identify(base3);
	std::cout << "------------------------------------------------------\n" << std::endl;

	std::cout << "--------------- IDENTIFY ADDRESS CALLS ---------------" << std::endl;
	identify(*base1);
	identify(*base2);
	identify(*base3);
	std::cout << "------------------------------------------------------" << std::endl;

	delete base1;
	delete base2;
	delete base3;

	std::getwchar();
	return (0);
}
