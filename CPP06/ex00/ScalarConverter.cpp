#include "ScalarConverter.hpp"

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

/**
 * test cases:
 * 1. empty string
 * 2. "0.0"
 * 3. "42.0f"
*/
static bool printChar(string& input) {
    if (input.empty()) {
        std::cout << "char: impossible" << std::endl;
        return false;
    }
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    if (std::atoi(input.c_str()) && (std::atoi(input.c_str()) < 32 || std::atoi(input.c_str()) > 126)) {
        std::cout << "char: Non displayable" << std::endl;
        return false;
    }

    char character = static_cast<char>(input[0]);

    std::cout << "char: '" << character << "'" << std::endl;
    return true;
}

static bool isInvalid(string& input) {
    string possibleErrors[16] = {"inff", "-inff", "+inff", "nanf", "inf", "-inf", "+inf", "nan", "INFF", "-INFF", "+INFF", "NANF", "INF", "-INF", "+INF", "NAN"};

    for (int i = 0; i < 16; i++) {
        if (input == possibleErrors[i]) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << strtof(input.c_str(), NULL) << "f\n";
            std::cout << "double: " << strtod(input.c_str(), NULL) << "\n";
            return true;
        }
    }
    return false;
}

// input should be a c++ literal
// could be a char, int (base-10), float (base-10) or double (base-10)
// if the conversion is not possible, display "impossible"
void ScalarConverter::convert(string input) {
    if (isInvalid(input))
        return;
    printChar(input);
    // printInt(input);
    // printFloat(input);
    // printDouble(input);
}
