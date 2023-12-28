#include "Form.hpp"
#include <iostream>

Form::Form(): _name("Default"),
    _signed(false),
    _gradeToSign(150),
    _gradeToExecute(150) {
    DEBUG_MESSAGE("Form default constructor called", GRAY);
}

Form::~Form() {
    DEBUG_MESSAGE("Form destructor called", GRAY);
}

Form::Form(const Form& copy): _name(copy._name),
    _signed(copy._signed),
    _gradeToSign(copy._gradeToSign),
    _gradeToExecute(copy._gradeToExecute) {
    DEBUG_MESSAGE("Form copy constructor called", GRAY);
}

Form& Form::operator=(const Form& copy) {
    DEBUG_MESSAGE("Form assignation operator called", GRAY);
    if (this != &copy) {
        _signed = copy._signed;
    }
    return *this;
}

// getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
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

void Form::signForm(const Bureaucrat& bureaucrat) {
    try {
        beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
    }
    catch (std::exception& error) {
        std::cout << bureaucrat.getName() << " cannot sign " << _name << " because " << error.what() << std::endl;
    }
}

// exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return RED "Grade is too high" WHITE;
}

const char* Form::GradeTooLowException::what() const throw() {
    return RED "Grade is too low" WHITE;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute" << std::endl;
    return os;
}