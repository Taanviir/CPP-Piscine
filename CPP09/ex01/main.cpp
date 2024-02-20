#include "RPN.hpp"
#include <fstream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: invalid arguments" << std::endl;
        std::cout << "Usage: ./RPN [reversed Polish expression]" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    if (expression.empty()) {
        std::cout << "Error: invalid expression" << std::endl;
        return 1;
    }
    try {
        RPN::calculate(expression);
    }
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
        return 1;
    }

    #ifdef TEST
    std::ifstream file("tests.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            try {
                RPN::calculate(line);
            }
            catch (std::exception &error) {
                std::cout << error.what() << std::endl;
            }
            std::cout << std::endl;
        }
    }
    #endif

    return 0;
}
