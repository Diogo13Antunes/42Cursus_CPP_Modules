#pragma once

#include <AForm.hpp>
#include <fstream>

class PresidentialPardonForm: public AForm
{
	public:

		void	execute(const Bureaucrat &executor) const;

		PresidentialPardonForm  &operator=(const PresidentialPardonForm &src);

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm();
		~PresidentialPardonForm();

	private:
		std::string	_target;

};
