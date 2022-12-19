#include <easyfind.hpp>
#include <vector>

int main()
{
	std::vector<int> vect;

	std::cout << vect.size() << std::endl;

	vect.push_back(0);
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(5);

	std::cout << vect.size() << std::endl;

	std::cout << "========================================" << std::endl;
	for (unsigned long i = 0; i < vect.size(); i++)
		std::cout << "[" << vect[i] << "] ";
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		if (easyfind(vect, i) == true)
			std::cout << "Find [" << i << "]: True" << std::endl;
		else
			std::cout << "Find [" << i << "]: False" << std::endl;
	}
	return (0);
}
