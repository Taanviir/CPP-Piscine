#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& copy) {
    (void)copy;
}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& copy) {
    (void)copy;
    return *this;
}

std::stack<int> RPN::_numberStack;

static bool istoken(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int RPN::extractNumber(std::string::const_iterator &strItr) {
    int number = 0;
    int isNegative = 1;
    if (*strItr == '-') {
        isNegative = -1;
        strItr++;
    }
    else if (*strItr == '+') {
        strItr++;
    }
    while (isdigit(*strItr)) {
        number = number * 10 + (*strItr - '0');
        strItr++;
    }
    if (*strItr && *strItr != ' ') {
        while (!_numberStack.empty())
            _numberStack.pop();
        throw std::runtime_error("Error: Invalid character in input");
    }
    return number * isNegative;
}

void RPN::calculate(std::string const& input) {
    for (std::string::const_iterator strItr = input.begin();
        *strItr != '\0'; strItr++)
    {
        if (*strItr == ' ') // skip spaces
            continue;
        else if (istoken(*strItr) && _numberStack.size() >= 2) {
            int a = _numberStack.top(); // a is the first number popped
            _numberStack.pop();

            int b = _numberStack.top(); // b is the second number popped
            _numberStack.pop();

            if (*strItr == '+')
                _numberStack.push(b + a);
            else if (*strItr == '-')
                _numberStack.push(b - a);
            else if (*strItr == '*')
                _numberStack.push(b * a);
            else if (*strItr == '/') {
                if (a == 0)
                    throw std::runtime_error("Error: Division by zero is not allowed");
                _numberStack.push(b / a);
            }
        }
        else if (isdigit(*strItr) || *strItr == '-' || *strItr == '+') {
            int number = extractNumber(strItr);
            if (number > 9)
                throw std::runtime_error("Error: Number is too large");
            else if (number < 0)
                throw std::runtime_error("Error: Number is too small");
            _numberStack.push(number);
        }
        else
            throw std::runtime_error("Error: Invalid character in input");
    }
    if (_numberStack.size() != 1)
        throw std::runtime_error("Error: Missing operator in input");

    std::cout << _numberStack.top() << std::endl;

    // clear the stack for the next input
    while (!_numberStack.empty())
        _numberStack.pop();
}
