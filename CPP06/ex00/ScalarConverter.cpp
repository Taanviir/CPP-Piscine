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
    DEBUG_MESSAGE("ScalarConverter assignation operator called", GRAY);
    (void) copy;
    return *this;
}

