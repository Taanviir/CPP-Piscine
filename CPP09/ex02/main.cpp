#include <string>
#include <cstdlib>
#include <limits>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./PmergeMe [num1] [num2] ... [numN]" << std::endl;
        return 1;
    }

    std::string numbers;
    for (int i = 1; i < argc; i++) {
        numbers += argv[i];
        numbers += " ";
    }
    if (numbers.find("-") != std::string::npos) {
        std::cout << "Error: Invalid input" << std::endl;
        return 1;
    }

    int size = argc - 1;
    int* array = new int[size];
    for (int i = 1; i < argc; i++) {
        double num = strtod(argv[i], NULL);
        if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
            std::cout << "Error: Invalid input" << std::endl;
            delete[] array;
            return 1;
        }
        array[i - 1] = static_cast<int>(num);
    }

    PmergeMe pmergeMe(array, size);

    delete [] array;
    return 0;
}
