#include <Bureaucrat.hpp>

void	testInitialGrade(std::string name, int grade)
{
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat a(name, grade);
		std::cout << a << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	testDecrementation(std::string name, int grade)
{
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat a(name, grade);
		std::cout << a << std::endl;
		for (int i = 0; i < 150; i++)
			a.gradeDecrement();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	testIncrementation(std::string name, int grade)
{
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat a(name, grade);
		std::cout << a << std::endl;
		for (int i = 150; i > 0; i--)
			a.gradeIncrement();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	testGetters(std::string name, int grade)
{
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat a(name, grade);
		std::cout << std::endl;
		std::cout << "<===============================>" << std::endl;
		std::cout << a << std::endl;
		std::cout << "<===============================>" << std::endl;
		std::cout << "Name:  " << a.getName() << std::endl;
		std::cout << "Grade: " << a.getGrade() << std::endl;
		std::cout << "<===============================>" << std::endl;
		std::cout << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
}

int main()
{
	testInitialGrade("Test1", 1);
	testInitialGrade("Test2", 150);
	testInitialGrade("Test3", 0);
	testInitialGrade("Test4", 151);

	testIncrementation("Test5", 150);

	testDecrementation("Test6", 1);

	testGetters("TEST07", 13);

	return (0);
}
