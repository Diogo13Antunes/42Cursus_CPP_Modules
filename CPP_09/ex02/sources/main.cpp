#include <PmergeMe.hpp>

#include <cstdio>
#include <cmath>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		int	n = ac - 1;
		PmergeMe	merge(av, n);

		std::cout << "Non Sorted: ";
		merge.printVectorData();

		merge.sort();

		std::cout << "Sorted: ";
		merge.printVectorData();

		merge.printTimes();

		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
