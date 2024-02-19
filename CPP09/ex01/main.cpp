#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: invalid arguments" << std::endl;
        std::cout << "Usage: ./RPN [reversed Polish expression]" << std::endl;
        return 1;
    }
    std::string expression = argv[1];
    return 0;
}
