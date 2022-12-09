#include <Interm.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

Interm::Interm()
{
	// std::cout << "Interm Default Constructor" << std::endl;
	this->_formsList[0].formName = "shrubbery creation";
	this->_formsList[0].formFunction = &Interm::createShrubberyCreationForm;
	this->_formsList[1].formName = "robotomy request";
	this->_formsList[1].formFunction = &Interm::createRobotomyRequestForm;
	this->_formsList[2].formName = "presidential pardon";
	this->_formsList[2].formFunction = &Interm::createPresidentialPardonForm;
}

Interm::Interm(const Interm &src)
{
	*this = src;
}

Interm	&Interm::operator=(const Interm &src)
{
	for (int i = 0; i < NBR_FORMS; i++)
	{
		this->_formsList[i].formName = src._formsList[i].formName;
		this->_formsList[i].formFunction = src._formsList[i].formFunction;
	}
	return (*this);
}

Interm::~Interm()
{
	// std::cout << "Interm Default Destructor" << std::endl;
}

AForm *Interm::createShrubberyCreationForm(std::string target)
{
	AForm *newForm = new ShrubberyCreationForm(target);
	return (newForm);
}

AForm *Interm::createRobotomyRequestForm(std::string target)
{
	AForm *newForm = new RobotomyRequestForm(target);
	return (newForm);
}

AForm *Interm::createPresidentialPardonForm(std::string target)
{
	AForm *newForm = new PresidentialPardonForm(target);
	return (newForm);
}

AForm *Interm::makeForm(std::string formType, std::string formTarget)
{
	AForm	*newForm = NULL;

	for (int i = 0; i < NBR_FORMS; i++)
	{
		if (this->_formsList[i].formName.compare(formType) == 0)
		{
			newForm = (this->*_formsList[i].formFunction)(formTarget);	
			std::cout << "Intern creates " << formType << std::endl;
			return (newForm);
		}
	}
	std::cout << "Interm could not create the form " << formType << std::endl;
	return (newForm);
}
