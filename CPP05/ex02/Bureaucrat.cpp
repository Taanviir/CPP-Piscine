#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat():
    _name("Default"),
    _grade(150) {
    DEBUG_MESSAGE("Bureaucrat default constructor called", BLUE);
}

Bureaucrat::~Bureaucrat() {
    DEBUG_MESSAGE("Bureaucrat destructor called for " << _name, BLUE);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy):
    _name(copy._name),
    _grade(copy._grade) {
    DEBUG_MESSAGE("Bureaucrat copy constructor called", BLUE);
}

Bureaucrat::Bureaucrat(const std::string& name):
    _name(name.empty() ? "Default" : name),
    _grade(150) {
    DEBUG_MESSAGE("Bureaucrat constructor called for " << _name, BLUE);

    if (_name == "Default")
        std::cout << RED "Bureaucrat name cannot be empty, setting name to \"Default\"" WHITE << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade):
    _name(name.empty() ? "Default" : name),
    _grade(grade) {
    DEBUG_MESSAGE("Bureaucrat grade constructor called for " << _name, BLUE);

    if (_name == "Default")
        std::cout << RED "Bureaucrat name cannot be empty, setting name to \"Default\"" WHITE << std::endl;

    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    DEBUG_MESSAGE("Bureaucrat copy assignment operator called", BLUE);
    _grade = copy._grade;
    return *this;
}

const std::string& Bureaucrat::getName(void) const {
    return _name;
}

int Bureaucrat::getGrade(void) const {
    return _grade;
}

void Bureaucrat::incrementGrade(void) {
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << YELLOW_B << this->_name << WHITE << " signed "
        << YELLOW_B << form.getName() << WHITE << std::endl;
    }
    catch (std::exception& error) {
        std::cout << YELLOW_B << this->_name << WHITE << " couldn't sign "
        << YELLOW_B << _name << WHITE << " because " << error.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << YELLOW_B << this->_name << WHITE << " executed "
        << YELLOW_B << form.getName() << WHITE << std::endl;
    }
    catch (std::exception& error) {
        std::cout << YELLOW_B << this->_name << WHITE << " couldn't execute "
        << YELLOW_B << form.getName() << WHITE << " because " << error.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return RED "Grade too high" WHITE;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return RED "Grade too low" WHITE;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other) {
    out << YELLOW_B << other.getName() << WHITE << ", bureaucrat grade " << YELLOW_B << other.getGrade() << WHITE;
    return out;
}
