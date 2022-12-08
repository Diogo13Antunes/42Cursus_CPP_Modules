#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45)
{
	_target = "Random_Target";
	// std::cout << "Default RobotomyRequestForm Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	// std::cout << "Target RobotomyRequestForm Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->_target = src._target;
	this->_signStatus = src._signStatus;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Default RobotomyRequestForm Destructor" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	srand((unsigned) time(NULL));
	if (executor.getGrade() <= this->_gradeToExecute  && _signStatus)
	{
		int randomResult = (rand() % 10) + 1;

		std::cout << "Drilling Noises" << std::endl;
		if (randomResult >= 5)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomized failed" << std::endl;
	}
	else
	{
		throw GradeTooLowException();
	}
}
