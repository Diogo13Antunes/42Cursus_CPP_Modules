#include "Harl.hpp"

int main()
{
	Harl		complains;
	std::string	array[5];

	array[0] = "INFO";
	array[1] = "ERROR";
	array[2] = "DEBUG";
	array[3] = "WARNING";
	array[4] = "CODE";

	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << "\t";
		complains.complain(array[i]);
	}
}
