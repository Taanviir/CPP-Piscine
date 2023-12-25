#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);

    // print
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    // invalid grade
    try {
        Bureaucrat b3("b3", 0);
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    try {
        Bureaucrat b4("b4", 151);
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    // increment grade
    try {
        b1.incrementGrade();
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    try {
        b2.incrementGrade();
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    // decrement grade
    try {
        b1.decrementGrade();
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    try {
        b2.decrementGrade();
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
