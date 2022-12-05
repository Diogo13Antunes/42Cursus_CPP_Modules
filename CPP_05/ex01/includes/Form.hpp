#pragma once

#include <string>
#include <iostream>

#define HIGHEST_GRADE  1
#define LOWEST_GRADE   150

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
        const int           getGradeToSign(void) const;
        const int           getGradeToExecute(void) const;
        bool                getSignStatus(void) const;

        Form  &operator=(const Form &src);

        Form(const Form &src);
        Form(const std::string name, const int grade);
        Form();
        virtual ~Form();

    private:
        const std::string   _name;
        bool                _signStatus;
        const int           _gradeToSign;
        const int           _gradeToExecute;
};

std::ostream    &operator<< (std::ostream &os, const Form &src);
