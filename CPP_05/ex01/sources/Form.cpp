#include <Form.hpp>

Form::Form():
	_name("Form_Name"), _signStatus(false), _gradeToSign(1), _gradeToExecute(1)
{
	// std::cout << "Default Form Constructor" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec):
	_name(name), _signStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	// std::cout << "Grade Form Constructor" << std::endl;
}

Form::Form(const Form &src):
	_name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

Form::~Form()
{
	// std::cout << "Default Form Destructor" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	this->_signStatus = src.getSignStatus();
	return (*this);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too Hight");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too Low");
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool	Form::getSignStatus(void) const
{
	return (this->_signStatus);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	int	bGrade = bureaucrat.getGrade();

	if (bGrade <= this->_gradeToSign)
	{
		this->_signStatus = true;
		bureaucrat.signForm(this->_name, this->_signStatus);
	}
	else
	{
		bureaucrat.signForm(this->_name, this->_signStatus);
		throw GradeTooLowException();
	}
}

std::ostream    &operator<< (std::ostream &os, const Form &src)
{
	os << "---------------------------------" << std::endl;
	os << "Form Name      -> " << src.getName() << std::endl;
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
