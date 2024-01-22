#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {
    DEBUG_MESSAGE("ScalarConverter default constructor called", GRAY);
}

ScalarConverter::~ScalarConverter() {
    DEBUG_MESSAGE("ScalarConverter destructor called", GRAY);
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    DEBUG_MESSAGE("ScalarConverter copy constructor called", GRAY);
    (void) copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    DEBUG_MESSAGE("ScalarConverter assignment operator called", GRAY);
    (void) copy;
    return *this;
}

std::string error_input[10] = {
    "-inff",
    "+inff",
    "inff",
    "nanf",
    "-inf",
    "+inf",
    "inf",
    "nan"
};
// input should be a c++ literal
// could be a char, int (base-10), float (base-10) or double (base-10)
// if the conversion is not possible, display "impossible"
// if the conversion is not displayable, display "Non displayable"
void ScalarConverter::convert(std::string input) {

    printChar(input);
    // printInt(input);
    // printFloat(input);
    // printDouble(input);
}
