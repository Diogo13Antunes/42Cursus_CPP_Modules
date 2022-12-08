#pragma once

#include <AForm.hpp>
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
	public:

		void	execute(const Bureaucrat &executor) const;

		RobotomyRequestForm  &operator=(const RobotomyRequestForm &src);

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm();
		~RobotomyRequestForm();

	private:
		std::string	_target;

};
