#include <string>
#include <cstdlib>
#include <limits>
#include "PmergeMe.hpp"

bool isSorted(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

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
        std::cout << "Error: Negative numbers detected." << std::endl;
        return 1;
    }

    int size = argc - 1;
    int* array = new int[size];
    for (int i = 1; i < argc; i++) {
        double num = strtod(argv[i], NULL);
        if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
            std::cout << "Error: Input is beyond integer range" << std::endl;
            delete [] array;
            return 1;
        }
        array[i - 1] = static_cast<int>(num);
    }

    if (isSorted(array, size)) {
        std::cout << "Error: Array is already sorted." << std::endl;
        delete [] array;
        return 1;
    }

    PmergeMe pmergeMe(array, size);

    std::sort(array, array + size);
    for (int i = 0; i < size - 1; i++) {
        if (array[i] == array[i + 1]) {
            std::cout << "Error: Duplicate numbers detected." << std::endl;
            delete [] array;
            return 1;
        }
    }

    try {
        pmergeMe.sort();
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
        delete [] array;
        return 1;
    }

    delete [] array;
    return 0;
}
