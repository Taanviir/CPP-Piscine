#include "Form.hpp"
#include <iostream>

Form::Form():
    _name("Default"),
    _signed(false),
    _gradeToSign(150),
    _gradeToExecute(150) {
    DEBUG_MESSAGE("Form default constructor called", GRAY);
}

Form::~Form() {
    DEBUG_MESSAGE("Form destructor called", GRAY);
}

Form::Form(const Form& copy):
    _name(copy._name),
    _signed(copy._signed),
    _gradeToSign(copy._gradeToSign),
    _gradeToExecute(copy._gradeToExecute) {
    DEBUG_MESSAGE("Form copy constructor called", GRAY);
}

Form::Form(const std::string& name):
    _name(name.empty() ? "Default" : name),
    _signed(false),
    _gradeToSign(150),
    _gradeToExecute(150) {
    DEBUG_MESSAGE("Form constructor called", GRAY);

    if (name == "Default") {
        std::cout << "Invalid name entered, Form name set to default" << std::endl;
    }
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
    _name(name.empty() ? "Default" : name),
    _signed(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
    DEBUG_MESSAGE("Form constructor called", GRAY);

    if (name == "Default") {
        std::cout << "Invalid name entered, Form name set to default" << std::endl;
    }

    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

// overloading = operator
Form& Form::operator=(const Form& copy) {
    DEBUG_MESSAGE("Form copy assignment operator called", GRAY);
    if (this != &copy) {
        _signed = copy._signed;
    }
    return *this;
}

// getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// methods
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

// exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return RED "Bureaucrat grade is too high" WHITE;
}

const char* Form::GradeTooLowException::what() const throw() {
    return RED "Bureaucrat grade is too low" WHITE;
}

// overloading << operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << YELLOW_B << form.getName() << WHITE
    << " is " << (form.getIsSigned() ? "signed" : "not signed")
    << " and requires grade " << form.getGradeToSign() << " to sign and grade "
    << form.getGradeToExecute() << " to execute" << std::endl;
    return os;
}