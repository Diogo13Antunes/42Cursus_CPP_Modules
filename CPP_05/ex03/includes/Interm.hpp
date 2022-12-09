#pragma once

#include <iostream>
#include <string>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Interm;

#define NBR_FORMS   3

typedef struct s_forms
{
    std::string formName;
    AForm*       (Interm::*formFunction)(std::string);
}               t_forms;

class Interm
{
    public:

        AForm   *createShrubberyCreationForm(std::string target);
        AForm   *createRobotomyRequestForm(std::string target);
        AForm   *createPresidentialPardonForm(std::string target);

        AForm   *makeForm(std::string formType, std::string formTarget);

        Interm &operator=(const Interm &src);

        Interm(const Interm &src);
        Interm();
        ~Interm();

    private:
        t_forms _formsList[NBR_FORMS];

};
