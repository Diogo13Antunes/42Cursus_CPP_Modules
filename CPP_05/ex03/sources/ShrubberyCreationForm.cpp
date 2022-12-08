#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "Random_Target";
	// std::cout << "Default ShrubberyCreationForm Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	// std::cout << "Target ShrubberyCreationForm Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_target = src._target;
	this->_signStatus = src._signStatus;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "Default ShrubberyCreationForm Destructor" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= this->_gradeToExecute && _signStatus)
	{
		std::string	fileName = this->_target + "_shrubbery";
		std::ofstream newFile(fileName.c_str());

		newFile << std::endl;
		newFile << "   	 /\\              " << std::endl;
		newFile << "      /\\*\\          " << std::endl;
		newFile << "     /\\O\\*\\        " << std::endl;
		newFile << "    /*/\\/\\/\\       " << std::endl;
		newFile << "   /\\O\\/\\*\\/\\    " << std::endl;
		newFile << "  /\\*\\/\\*\\/\\/\\  " << std::endl;
		newFile << " /\\O\\/\\/*/\\/O/\\  " << std::endl;
		newFile << "       ||             " << std::endl;
		newFile << "       ||             " << std::endl;
		newFile << "       ||             " << std::endl;
		newFile.close();
		std::cout << this->_name << " executed by " << executor.getName() << std::endl;
	}
	else
		throw GradeTooLowException();
}
