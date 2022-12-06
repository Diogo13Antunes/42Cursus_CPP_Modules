#pragma once

#include <string>
#include <iostream>

#include <Bureaucrat.hpp>

class Form
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

        const std::string   getName(void) const;
        int                 getGradeToSign(void) const;
        int                 getGradeToExecute(void) const;
        bool                getSignStatus(void) const;

        void                beSigned(const Bureaucrat &bureaucrat);

        Form  &operator=(const Form &src);

        Form(const Form &src);
        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        Form();
        virtual ~Form();

    private:
        const std::string   _name;
        bool                _signStatus;
        const int           _gradeToSign;
        const int           _gradeToExecute;
};

std::ostream    &operator<< (std::ostream &os, const Form &src);
