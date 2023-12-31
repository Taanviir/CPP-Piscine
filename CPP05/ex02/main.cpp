#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat bureaucrat("tanvir", 2);
    // AForm form("test", 1, 1); // cannot instantiate abstract class

    // testing ShrubberyCreationForm
    {
        ShrubberyCreationForm shrub("test");

        shrub.beSigned(bureaucrat);
        bureaucrat.executeForm(shrub);
    }

    std::cout << std::endl;

    // testing RobotomyRequestForm
    {
        RobotomyRequestForm robot("test");

        robot.beSigned(bureaucrat);
        bureaucrat.executeForm(robot);
    }

    std::cout << std::endl;

    // testing PresidentialPardonForm
    {
        PresidentialPardonForm president("test");

        president.beSigned(bureaucrat);
        bureaucrat.executeForm(president);
    }

    std::cout << std::endl;

    // testing exceptions
    {
        try {
            ShrubberyCreationForm shrub("test");
            bureaucrat.executeForm(shrub);
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }

        std::cout << std::endl;

        try {
            RobotomyRequestForm robot("test");
            bureaucrat.executeForm(robot);
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }

        std::cout << std::endl;

        try {
            PresidentialPardonForm president("test");
            bureaucrat.executeForm(president);
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }
    }

    std::cout << std::endl;

    // testing invalid bureaucrat grade
    {
        try {
            ShrubberyCreationForm shrub("test");
            Bureaucrat bureaucrat("incorrect", 150);
            shrub.beSigned(bureaucrat);
            bureaucrat.executeForm(shrub);
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
}
