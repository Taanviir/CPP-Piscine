#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():
    AForm("RobotomyRequestForm", 72, 45) {
    DEBUG_MESSAGE("RobotomyRequestForm default constructor called", GRAY_BG);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    DEBUG_MESSAGE("RobotomyRequestForm destructor called", GRAY_BG);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):
    AForm(copy) {
    DEBUG_MESSAGE("RobotomyRequestForm copy constructor called", GRAY_BG);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
    AForm("RobotomyRequestForm", 72, 45),
    _target(target.empty() ? "Default" : target) {
    DEBUG_MESSAGE("RobotomyRequestForm constructor called", GRAY_BG);

    if (target == "Default") {
        std::cout << "Invalid target entered, RobotomyRequestForm target set to default" << std::endl;
    }
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    DEBUG_MESSAGE("RobotomyRequestForm copy assignment operator called", GRAY_BG);
    if (this == &copy) return *this;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
        return;
    } else if (!this->getSignedStatus()) {
        throw FormNotSignedException();
        return;
    }

    std::srand(time(NULL));

    std::cout << "*BZZZZZZ... BBBZZZZZZZZZZ...*" << std::endl;
    int randomValue = std::rand();
    if (randomValue % 2) {
        std::cout << "Operation successful! " << this->_target << " is now robotomized 🤖" << std::endl;
    } else {
        std::cout << "Operation failed! Unable to robotomize " << this->_target << std::endl;
    }
}