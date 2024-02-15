#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    // testing int array
    std::cout << "Testing int array:" << std::endl;
    Array<int> arr(5);
    for (int i = 0; i < arr.size(); i++)
        arr[i] = i;
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    try {
        arr[6] = 6;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    // testing string array
    std::cout << "Testing string array:" << std::endl;
    Array<std::string> arr2(3);
    arr2[0] = "Hello";
    arr2[1] = "World";
    arr2[2] = "!";
    for (int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    try {
        arr2[3] = "!";
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    // testing default constructor, copy constructor and assignment operator
    std::cout << "Testing default constructor, copy constructor and assignment operator:" << std::endl;
    Array<int> arr3;
    std::cout << arr3.size() << std::endl;

    Array<int> arr4(arr);
    for (int i = 0; i < arr4.size(); i++)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;

    Array<int> arr5;
    arr5 = arr;
    for (int i = 0; i < arr5.size(); i++)
        std::cout << arr5[i] << " ";
    std::cout << std::endl;

    return 0;
}
