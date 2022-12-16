#include <cstdlib>
#include <iostream>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base	*generate(void)
{
	Base	*newBase = NULL;

	int random = rand() % 100 + 1;
	if (random >= 1 && random < 33)
	{
		newBase = new A();
		std::cout << "Base A" << std::endl;
	}
	else if ((random >= 33 && random < 66))
	{
		newBase = new B();
		std::cout << "Base B" << std::endl;
	}
	else if (random >= 66)
	{
		newBase = new C();
		std::cout << "Base C" << std::endl;
	}
	return (newBase);
}
