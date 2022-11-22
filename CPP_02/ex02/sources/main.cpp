#include "Fixed.hpp"

int	main(void)
{
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "- Increment and decrement tests:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl << std::endl;
	a++;
	a++;

	std::cout << "b is: " << b << std::endl << std::endl;

	std::cout << "- Max and min tests:" << std::endl << std::endl;
	std::cout << "max test" << std::endl << Fixed::max( a, b ) << std::endl;
	std::cout << "max test" << std::endl << Fixed::max( a, (Fixed&) b ) << std::endl;
	std::cout << "min test" << std::endl << Fixed::min( a, b ) << std::endl;
	std::cout << "min test" << std::endl << Fixed::min( a, (Fixed&) b ) << std::endl << std::endl;
	
	std::cout << "- Operations:" << std::endl << std::endl;
	std::cout << "a is " << a << " and b is " << b << ':' << std::endl;
	std::cout << "*: " << a * b << std::endl;
	std::cout << "/: " << b / a << std::endl;
	std::cout << "-: " << a - b << std::endl;
	std::cout << "+: " << a + b << std::endl << std::endl;

	a = Fixed(25);
	std::cout << "- Comparison tests: a is " << a << " and b is " << b << ':' << std::endl;

	if (a < b)
		std::cout << "a is smaller than b" << std::endl;
	if (a > b)
		std::cout << "a is bigger" << std::endl;
	if (a <= b)
		std::cout << "a is smaller or equal to b" << std::endl;
	if (a >= b)
		std::cout << "a is bigger or equal to b" << std::endl;
	if (a == b)
		std::cout << "a is equal to b" << std::endl;
	if (a != b)
		std::cout << "a is not equal to b" << std::endl;

	return (0);
}
