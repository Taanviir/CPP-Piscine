#include "ScalarConverter.hpp"

inputType ScalarConverter::_type = ERROR;

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

static bool isInvalid(string& input) {
    string lowercaseInput = input;
    for (size_t i = 0; i < input.length(); i++) {
        lowercaseInput[i] = tolower(input[i]);
    }

    string possibleErrors[8] = {"inff", "-inff", "+inff", "nanf", "inf", "-inf", "+inf", "nan"};

    for (int i = 0; i < 8; i++) {
        if (lowercaseInput == possibleErrors[i]) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << strtof(lowercaseInput.c_str(), NULL) << "f\n";
            std::cout << "double: " << strtod(lowercaseInput.c_str(), NULL) << std::endl;
            return true;
        }
    }
    return false;
}

static inputType checkInput(string& input) {
    if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
        return CHAR;
    else if (input.find_first_of("+-") != input.find_last_of("+-")) // checking for multiple +-
        return ERROR;
    else if (input.find_first_not_of("+-0123456789") == string::npos) {
        if (input.find(".") == string::npos && input.length() > 10)
            return DOUBLE;
        return INT;
    }
    else if (input.find_first_not_of("+-0123456789.f") == string::npos) {
        // handle multiple . and f in input
        if (input.find_first_of(".") != input.find_last_of(".")) {
            std::cout << "Error: multiple '.' in input." << std::endl;
            return ERROR;
        }
        else if (input.find_first_of("f") != input.find_last_of("f")) {
            std::cout << "Error: multiple 'f' in input." << std::endl;
            return ERROR;
        }
        else if (!isdigit(input[input.find(".") + 1])) {
            std::cout << "Error: invalid decimal input." << std::endl;
            return ERROR;
        }
        // float will have f, double will not
        if (input.find("f") != string::npos) {
            if (input[input.find("f") + 1] != '\0') {
                std::cout << "Error: invalid float input." << std::endl;
                return ERROR;
            }
            return FLOAT;
        }
        else {
            return DOUBLE;
        }
    }
    std::cout << "Error: invalid input." << std::endl;
    return ERROR;
}

static void printChar(string& input, inputType type) {
    if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0])) {
        std::cout << "char: '" << input[0] << "'" << std::endl;
    }
    else if (type == INT || type == FLOAT || type == DOUBLE) {
        long int number = strtod(input.c_str(), NULL);
        if (number >= 0 && number <= MAX_UCHAR) {
            if (isprint(number))
                std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
    }
}

static void printInt(string& input, inputType type) {
    double number = 0;
    if (type == CHAR)
        number = input[0];
    else if (type == INT)
        number = strtol(input.c_str(), NULL, 10);
    else if (type == FLOAT)
        number = strtof(input.c_str(), NULL);
    else if (type == DOUBLE)
        number = std::strtod(input.c_str(), NULL);

    if (number > MAX_INT || number < MIN_INT)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;
}

static void printDecimal(string& input, inputType type) {
    double number = 0;
    if (type == CHAR)
        number = input[0];
    else if (type == INT || type == FLOAT || type == DOUBLE)
        number = strtod(input.c_str(), NULL);

    if (number > MAX_FLOAT || number < MIN_FLOAT)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;

    if (number == HUGE_VAL || number == -HUGE_VAL || number != number)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
}

void ScalarConverter::convert(string input) {
    if (isInvalid(input))
        return;

    // check input type
    ScalarConverter::_type = checkInput(input);
    if (ScalarConverter::_type == ERROR)
        return;

    // print conversions
    printChar(input, ScalarConverter::_type);
    printInt(input, ScalarConverter::_type);
    printDecimal(input, ScalarConverter::_type);
}
