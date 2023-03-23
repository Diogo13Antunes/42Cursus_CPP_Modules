#include <PmergeMe.hpp>

#include <cstdio>
#include <cmath>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		std::cout << std::endl;

		int	n = ac - 1;
		PmergeMe	merge(av, n);
		
		std::cout << std::endl;

		std::cout << "==========================================================" << std::endl;
		std::cout << "Vector\n";
		merge.printVectorData();
		std::cout << "==========================================================" << std::endl;

		std::cout << "==========================================================" << std::endl;
		std::cout << "Deque\n";
		merge.printDequeData();
		std::cout << "==========================================================" << std::endl;

		merge.sort();

		std::cout << "==========================================================" << std::endl;
		std::cout << "Vector\n";
		merge.printVectorData();
		std::cout << "==========================================================" << std::endl;

		std::cout << "==========================================================" << std::endl;
		std::cout << "Deque\n";
		merge.printDequeData();
		std::cout << "==========================================================" << std::endl;

		std::cout << std::endl;

		merge.sort();

		std::cout << std::endl;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
