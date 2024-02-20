#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./PmergeMe [num1] [num2] ... [numN]" << std::endl;
        return 1;
    }
    return 0;
}
