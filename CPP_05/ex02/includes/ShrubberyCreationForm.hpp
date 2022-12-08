#pragma once

#include <AForm.hpp>
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	public:

		void	execute(const Bureaucrat &executor) const;

		ShrubberyCreationForm  &operator=(const ShrubberyCreationForm &src);

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm();
		~ShrubberyCreationForm();

	private:
		std::string	_target;

};
