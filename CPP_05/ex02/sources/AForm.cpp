#include <AForm.hpp>

AForm::AForm():
	_name("AForm_Name"), _signStatus(false), _gradeToSign(1), _gradeToExecute(1)
{
	// std::cout << "Default AForm Constructor" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec):
	_name(name), _signStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	// std::cout << "Grade AForm Constructor" << std::endl;
}

AForm::AForm(const AForm &src):
	_name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

AForm::~AForm()
{
	// std::cout << "Default AForm Destructor" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	this->_signStatus = src.getSignStatus();
	return (*this);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too Hight");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too Low");
}

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool	AForm::getSignStatus(void) const
{
	return (this->_signStatus);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	int	bGrade = bureaucrat.getGrade();

	if (this->_signStatus == true)
	{
		bureaucrat.signForm(this->_name, this->_signStatus, "is already signed");
	}
	else if (bGrade <= this->_gradeToSign)
	{
		this->_signStatus = true;
		bureaucrat.signForm(this->_name, this->_signStatus, "");
	}
	else
	{
		bureaucrat.signForm(this->_name, this->_signStatus, "Grade is too Low");
		throw GradeTooLowException();
	}
}

std::ostream    &operator<< (std::ostream &os, const AForm &src)
{
	os << "---------------------------------" << std::endl;
	os << "AForm Name     -> " << src.getName() << std::endl;
	os << "Grade to Sign  -> " << src.getGradeToSign() << std::endl;
	os << "Grade to Exec  -> " << src.getGradeToExecute() << std::endl;
	os << "Sign Status    -> ";
	if (src.getSignStatus())
		os << "Signed";
	else
		os << "Not Signed";
	os << std::endl;
	os << "---------------------------------";
	return (os);
}
