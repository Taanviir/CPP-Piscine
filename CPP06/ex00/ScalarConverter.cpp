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

/**
 * test cases:
 * 1. empty string
 * 2. "0.0"
 * 3. "42.0f"
*/
static void printChar(std::string& input) {
    if (input.empty()) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (input == error_input[i]) {
            std::cout << "char: impossible" << std::endl;
            return;
        }
    }
    if (std::atoi(input.c_str()) && (std::atoi(input.c_str()) < 32 || std::atoi(input.c_str()) > 126)) {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }

    char character = static_cast<char>(input[0]);

    std::cout << "char: '" << character << "'" << std::endl;
}

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
