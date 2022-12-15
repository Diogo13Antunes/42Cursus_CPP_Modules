#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int main()
{
	Base	*base1 = generate();
	Base	*base2 = generate();
	Base	*base3 = generate();

	identify(base1);
	identify(base2);
	identify(base3);

	delete base1;
	delete base2;
	delete base3;

	std::getwchar();
	return (0);
}
