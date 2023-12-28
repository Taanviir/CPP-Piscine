#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Bureaucrats
    Bureaucrat b1("bureaucrat1", 1);
    Bureaucrat b2("bureaucrat2", 150);

    // Forms
    Form f1("form1", 1, 1);
    Form f2("form2", 150, 150);

    // Sign forms
    b1.signForm(f1);
    b2.signForm(f2);

    // Print forms
    std::cout << f1;
    std::cout << f2;

    // Try to sign forms with bureaucrats with too low grades
    try {
        Form f3("form3", 0, 1);
        std::cout << f3 << std::endl;
    }
    catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    try {
        Form f4("form4", 1, 0);
        std::cout << f4 << std::endl;
    }
    catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    // Try to sign forms with bureaucrats with too high grades
    try {
        Form f5("form5", 151, 1);
        std::cout << f5 << std::endl;
    }
    catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    try {
        Form f6("form6", 1, 151);
        std::cout << f6 << std::endl;
    }
    catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
