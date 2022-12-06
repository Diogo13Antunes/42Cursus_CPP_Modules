#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(): _name("Bureaucrat_Name"), _grade(1)
{
	std::cout << "Default Bureaucrat Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade):
	_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Grade Bureaucrat Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):
	_name(src._name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too Hight");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too Low");
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::gradeIncrement(void)
{
	int temp = this->_grade - 1;

	if (temp < 1)
		throw GradeTooHighException();
	else
		this->_grade = temp;
}

void	Bureaucrat::gradeDecrement(void)
{
	int temp = this->_grade + 1;

	if (temp > 150)
		throw GradeTooLowException();
	else
		this->_grade = temp;
}

std::ostream    &operator<< (std::ostream &os, const Bureaucrat &src)
{
	os << src.getName();
	os << ", bureaucrat grade ";
	os << src.getGrade();
	return (os);
}
