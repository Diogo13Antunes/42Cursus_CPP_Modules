#include <Form.hpp>

Form::Form(): _name("Form_Name"), _grade(1)
{
	std::cout << "Default Form Constructor" << std::endl;
}

Form::Form(const std::string name, const int grade):
	_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Grade Form Constructor" << std::endl;
}

Form::Form(const Form &src)
{
	*this = src;
}

Form::~Form()
{
	std::cout << "Default Form Destructor" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	this->_grade = src._grade;
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

int		Form::getGrade(void) const
{
	return (this->_grade);
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

void	Form::gradeIncrement(void)
{
	int temp = this->_grade - 1;

	if (temp < 1)
		throw GradeTooHighException();
	else
		this->_grade = temp;
}

void	Form::gradeDecrement(void)
{
	int temp = this->_grade + 1;

	if (temp > 150)
		throw GradeTooLowException();
	else
		this->_grade = temp;
}

std::ostream    &operator<< (std::ostream &os, const Form &src)
{
	os << src.getName();
	os << ", Form grade ";
	os << src.getGrade();
	return (os);
}
