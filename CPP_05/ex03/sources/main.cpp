#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Interm.hpp>

# define SHRUBBERY_FORM		"shrubbery creation"
# define ROBOTOMY_FORM 		"robotomy request"
# define PRESIDENTIAL_FORM	"presidential pardon"

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
	Interm	maker;
	Bureaucrat *b = createBureaucrat("Bot", 150);

	AForm *Shrubbery = maker.makeForm(SHRUBBERY_FORM, "Teste");
	AForm *Robotomy = maker.makeForm(ROBOTOMY_FORM, "Teste");
	AForm *Presidential = maker.makeForm(PRESIDENTIAL_FORM, "Teste");

	AForm *teste = maker.makeForm("Teste", "Teste");

	if (teste)
		std::cout << teste->getName() << std::endl;

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
