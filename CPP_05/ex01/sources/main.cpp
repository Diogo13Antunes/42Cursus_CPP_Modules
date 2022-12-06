#include <Bureaucrat.hpp>
#include <Form.hpp>

void	testInitialGrades(std::string name, int gradeToSign, int gradeToExec)
{
	std::cout << "************************************************************************************" << std::endl;
	try
	{
		Form a(name, gradeToSign, gradeToExec);
		std::cout << a << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "************************************************************************************" << std::endl;
	std::cout << std::endl;
}

void	testSign(Bureaucrat bureaucrat, Form form)
{
	std::cout << "************************************************************************************" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	try
	{
		form.beSigned(bureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << form << std::endl;
	std::cout << "************************************************************************************" << std::endl;
}

int main()
{
	testInitialGrades("Form_1", 1, 1);
	testInitialGrades("Form_2", 1, 150);
	testInitialGrades("Form_3", 150, 1);
	testInitialGrades("Form_4", 1, 0);
	testInitialGrades("Form_5", 0, 1);
	testInitialGrades("Form_6", 151, 1);
	testInitialGrades("Form_7", 1, 151);

	try
	{
		testSign(Bureaucrat("Dummy_1", 1), Form("Form_1", 1, 1));
		testSign(Bureaucrat("Dummy_2", 1), Form("Form_2", 150, 1));
		testSign(Bureaucrat("Dummy_3", 150), Form("Form_3", 150, 1));
		testSign(Bureaucrat("Dummy_4", 30), Form("Form_3", 50, 1));
		testSign(Bureaucrat("Dummy_5", 150), Form("Form_3", 1, 1));
		testSign(Bureaucrat("Dummy_6", 30), Form("Form_3", 13, 1));	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
