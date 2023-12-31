#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
    AForm("PresidentialPardonForm", 25, 5) {
    DEBUG_MESSAGE("PresidentialPardonForm default constructor called", MAGENTA);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    DEBUG_MESSAGE("PresidentialPardonForm destructor called", MAGENTA);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):
    AForm(copy) {
    DEBUG_MESSAGE("PresidentialPardonForm copy constructor called", MAGENTA);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
    AForm("PresidentialPardonForm", 25, 5),
    _target(target.empty() ? "Default" : target) {
    DEBUG_MESSAGE("PresidentialPardonForm constructor called", MAGENTA);

    if (target == "Default") {
        std::cout << "Invalid target entered, PresidentialPardonForm target set to default" << std::endl;
    }
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    DEBUG_MESSAGE("PresidentialPardonForm copy assignment operator called", MAGENTA);
    if (this == &copy) return *this;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
        return;
    } else if (!this->getSignedStatus()) {
        throw FormNotSignedException();
        return;
    }

    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}