#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
    DEBUG_MESSAGE("Intern default constructor called", GRAY);
}

Intern::~Intern() {
    DEBUG_MESSAGE("Intern destructor called", GRAY);
}

Intern::Intern(const Intern& copy) {
    DEBUG_MESSAGE("Intern copy constructor called", GRAY);
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
    DEBUG_MESSAGE("Intern copy assignment operator called", GRAY);
    if (this == &copy) return *this;
    return *this;
}

AForm* makeShrubberyCreationForm(std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* makeRobotomyRequestForm(std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* makePresidentialPardonForm(std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    DEBUG_MESSAGE("Intern makeForm called", GRAY);
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*formFunctions[3])(std::string&) = {
        makeShrubberyCreationForm,
        makeRobotomyRequestForm,
        makePresidentialPardonForm
    };
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Form " << formName << " created by intern" << std::endl;
            return formFunctions[i](target);
        }
    }
    throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return RED "Form not found" WHITE;
}
