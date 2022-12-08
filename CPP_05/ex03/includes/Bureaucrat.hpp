#pragma once

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
    public:

        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };

        int                 getGrade(void) const;
        const std::string   getName(void) const;

        void                gradeIncrement();
        void                gradeDecrement();

        void                signForm(std::string formName, bool formStatus, std::string msg) const;
        void	            executeForm(const AForm &form) const;

        Bureaucrat  &operator=(const Bureaucrat &src);

        Bureaucrat(const Bureaucrat &src);
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat();
        virtual ~Bureaucrat();

    private:
        const std::string   _name;
        int                 _grade;
};

std::ostream    &operator<< (std::ostream &os, const Bureaucrat &src);
