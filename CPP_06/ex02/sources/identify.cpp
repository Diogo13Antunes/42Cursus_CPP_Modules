#include <iostream>
#include <typeinfo>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

void	identify(Base *p)
{
	std::cout << "Base Type with Pointer: ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
	return ;
}

void	identify(Base &p)
{
	std::cout << "Base Type with Address: ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;		
	}
	catch(const std::bad_cast &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;	
		}
		catch(const std::bad_cast &e)
		{
			std::cout << "C" << std::endl;	
		}		
	}
	return ;
}
