#include <Array.hpp>

int main()
{
	Array<int>	novo;

	std::cout << novo.size() << std::endl;

	Array<int>	teste(novo);

	std::cout << teste.size() << std::endl;

	Array<int>	dummy(5);

	std::cout << dummy.size() << std::endl;

	for (unsigned int i = 0; i <= 5; i++)
	{
		try
		{
			dummy[i] = (i + 1) * 10;
			std::cout << "Dummy [" << i << "]: " << dummy[i] << std::endl;	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
