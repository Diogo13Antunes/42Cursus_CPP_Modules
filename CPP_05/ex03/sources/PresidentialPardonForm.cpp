#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5)
{
	_target = "Random_Target";
	// std::cout << "Default PresidentialPardonForm Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	// std::cout << "Target PresidentialPardonForm Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src)
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->_target = src._target;
	this->_signStatus = src._signStatus;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Default PresidentialPardonForm Destructor" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= this->_gradeToExecute && _signStatus)
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw GradeTooLowException();
}
