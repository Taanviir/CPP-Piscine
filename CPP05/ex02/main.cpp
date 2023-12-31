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
        shrub.execute(bureaucrat);
    }

    std::cout << std::endl;

    // testing RobotomyRequestForm
    {
        RobotomyRequestForm robot("test");

        robot.beSigned(bureaucrat);
        robot.execute(bureaucrat);
    }

    std::cout << std::endl;

    // testing PresidentialPardonForm
    {
        PresidentialPardonForm president("test");

        president.beSigned(bureaucrat);
        president.execute(bureaucrat);
    }

    std::cout << std::endl;

    // testing exceptions
    {
        try {
            ShrubberyCreationForm shrub("test");
            shrub.execute(bureaucrat);
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }

        std::cout << std::endl;


        try {
            RobotomyRequestForm robot("test");
            robot.execute(bureaucrat);
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }

        std::cout << std::endl;

        try {
            PresidentialPardonForm president("test");
            president.execute(bureaucrat);
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
            shrub.execute(bureaucrat);
        } catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
}
