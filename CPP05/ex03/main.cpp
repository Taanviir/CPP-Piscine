#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
    Intern newIntern;

    {
        std::string formName = "shrubbery creation";
        std::cout << "Trying to create form " << formName << std::endl;
        std::string target = "target";
        AForm* form = newIntern.makeForm(formName, target);
        std::cout << *form << std::endl;
        delete form;
    }

    {
        std::cout << "Trying to create form with invalid name" << std::endl;
        std::string target = "target";
        try {
            AForm* form = newIntern.makeForm("invalid name", target);
            std::cout << *form << std::endl;
            delete form;
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }
    }

    return 0;
}
