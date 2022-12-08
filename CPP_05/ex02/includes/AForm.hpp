#pragma once

#include <Bureaucrat.hpp>

class AForm
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

        virtual void        execute(const Bureaucrat &executor) const = 0;

        AForm  &operator=(const AForm &src);

        AForm(const AForm &src);
        AForm(const std::string name, const int gradeToSign, const int gradeToExec);
        AForm();
        virtual ~AForm();

    protected:
        const std::string   _name;
        bool                _signStatus;
        const int           _gradeToSign;
        const int           _gradeToExecute;
};

std::ostream    &operator<< (std::ostream &os, const AForm &src);
