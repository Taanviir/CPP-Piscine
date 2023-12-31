#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
    AForm("ShrubberyCreationForm", 145, 137) {
    DEBUG_MESSAGE("ShrubberyCreationForm default constructor called", GREEN);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    DEBUG_MESSAGE("ShrubberyCreationForm destructor called", GREEN);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
    AForm(copy) {
    DEBUG_MESSAGE("ShrubberyCreationForm copy constructor called", GREEN);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    AForm("ShrubberyCreationForm", 145, 137),
    _target(target.empty() ? "Default" : target) {
    DEBUG_MESSAGE("ShrubberyCreationForm constructor called", GREEN);

    if (target == "Default") {
        std::cout << "Invalid target entered, ShrubberyCreationForm target set to default" << std::endl;
    }
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    DEBUG_MESSAGE("ShrubberyCreationForm copy assignment operator called", GREEN);
    if (this == &copy) return *this;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
        return;
    } else if (!this->getSignedStatus()) {
        throw FormNotSignedException();
        return;
    }

    std::string fileName = this->_target + "_shrubbery";
    std::ofstream treeFile(fileName.c_str());
    for (int i = 0; i < 5; i++) {
        treeFile << "       _-_" << std::endl;
        treeFile << "    /~~   ~~\\" << std::endl;
        treeFile << " /~~         ~~\\" << std::endl;
        treeFile << "{               }" << std::endl;
        treeFile << " \\  _-     -_  /" << std::endl;
        treeFile << "   ~  \\\\ //  ~" << std::endl;
        treeFile << "_- -   | | _- _" << std::endl;
        treeFile << "  _ -  | |   -_" << std::endl;
        treeFile << "      // \\\\" << std::endl;
    }
    treeFile.close();
}