#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

# define SHRUBBERY_FORM		"ShrubberyCreationForm"
# define ROBOTOMY_FORM 		"RobotomyRequestForm"
# define PRESIDENTIAL_FORM	"PresidentialPardonForm"

/*

> ShrubberyCreationForm
>> Grade To Sign = 145
>> Grade To Exec = 137

> RobotomyRequestForm
>> Grade To Sign = 72
>> Grade To Exec = 45

> PresidentialPardonForm
>> Grade To Sign = 25
>> Grade To Exec = 5

*/

Bureaucrat *createBureaucrat(std::string name, int grade)
{
	Bureaucrat	*newBureaucrat = NULL;

	try
	{
		newBureaucrat = new Bureaucrat(name, grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (newBureaucrat);
}

AForm	*createForm(std::string target, std::string specifier)
{
	AForm	*newForm = NULL;

	try
	{
		if (specifier.compare(SHRUBBERY_FORM) == 0)
			newForm = new ShrubberyCreationForm(target);
		else if (specifier.compare(ROBOTOMY_FORM) == 0)
			newForm = new RobotomyRequestForm(target);
		else if (specifier.compare(PRESIDENTIAL_FORM) == 0)
			newForm = new PresidentialPardonForm(target);
		else
			return (newForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (newForm);
}

void	test1(const Bureaucrat *bureaucrat, AForm *form)
{
	try
	{
		form->beSigned(*bureaucrat);
		form->beSigned(*bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		const AForm *formRef = form;
		bureaucrat->executeForm(*formRef);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	Bureaucrat *b = createBureaucrat("Bot", 100);

	AForm *Shrubbery = createForm("Teste", SHRUBBERY_FORM);
	AForm *Robotomy = createForm("Teste", ROBOTOMY_FORM);
	AForm *Presidential = createForm("Teste", PRESIDENTIAL_FORM);

	if (!b || !Shrubbery || !Robotomy || !Presidential)
	{
		if (b)
			delete b;
		if (Shrubbery)
			delete Shrubbery;
		if (Robotomy)
			delete Robotomy;
		if (Presidential)
			delete Presidential;
		return (-1);
	}

	std::cout << *b << std::endl;
	std::cout << *Shrubbery << std::endl;
	std::cout << *Robotomy << std::endl;
	std::cout << *Presidential << std::endl;

	test1(b, Shrubbery);
	test1(b, Robotomy);
	test1(b, Presidential);

	std::cout << *Shrubbery << std::endl;
	std::cout << *Robotomy << std::endl;
	std::cout << *Presidential << std::endl;

	delete b;
	delete Shrubbery;
	delete Robotomy;
	delete Presidential;

}
