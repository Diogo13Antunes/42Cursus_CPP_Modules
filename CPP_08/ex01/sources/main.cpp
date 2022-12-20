#include <Span.hpp>
#include <cstdlib>
#include <ctime>

#define MAX_VALUE 100
#define MIN_VALUE 0

int main()
{
	Span teste1(5);

	srand(time(NULL));
	try
	{
		int random;
		for (int i = 0; i < 5; i++)
		{
			random = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
			std::cout << "NBR " << i << ": " << random << std::endl;
			teste1.addNumber(random);
		}
		std::cout << "Shortest Span: " << teste1.shortestSpan() << std::endl;
		std::cout << "Longest Span:  " << teste1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Impossible to add a new number!" << std::endl;
	}
	return (0);
}