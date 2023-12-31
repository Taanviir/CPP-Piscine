#include "AForm.hpp"
#include <iostream>

AForm::AForm():
    _name("Default"),
    _signedStatus(false),
    _gradeToSign(150),
    _gradeToExecute(150) {
    DEBUG_MESSAGE("Form default constructor called", GRAY);
}

AForm::~AForm() {
    DEBUG_MESSAGE("Form destructor called", GRAY);
}

AForm::AForm(const AForm& copy):
    _name(copy._name),
    _signedStatus(copy._signedStatus),
    _gradeToSign(copy._gradeToSign),
    _gradeToExecute(copy._gradeToExecute) {
    DEBUG_MESSAGE("Form copy constructor called", GRAY);
}

AForm::AForm(const std::string& name):
    _name(name.empty() ? "Default" : name),
    _signedStatus(false),
    _gradeToSign(150),
    _gradeToExecute(150) {
    DEBUG_MESSAGE("Form constructor called", GRAY);

    if (name == "Default") {
        std::cout << "Invalid name entered, Form name set to default" << std::endl;
    }
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):
    _name(name.empty() ? "Default" : name),
    _signedStatus(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
    DEBUG_MESSAGE("Form constructor called", GRAY);

    if (name == "Default") {
        std::cout << "Invalid name entered, Form name set to default" << std::endl;
    }

    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

// overloading = operator
AForm& AForm::operator=(const AForm& copy) {
    DEBUG_MESSAGE("Form copy assignment operator called", GRAY);
    if (this != &copy) {
        _signedStatus = copy._signedStatus;
    }
    return *this;
}

// getters
const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSignedStatus() const {
    return _signedStatus;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// methods
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    _signedStatus = true;
}

// exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return RED "Bureaucrat grade is too high" WHITE;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return RED "Bureaucrat grade is too low" WHITE;
}

const char* AForm::FormNotSignedException::what() const throw() {
    return RED "The form has not been signed!" WHITE;
}

// overloading << operator
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << YELLOW_B << form.getName() << WHITE
    << " is " << (form.getSignedStatus() ? "signed" : "not signed")
    << " and requires grade " << form.getGradeToSign() << " to sign and grade "
    << form.getGradeToExecute() << " to execute" << std::endl;
    return os;
}