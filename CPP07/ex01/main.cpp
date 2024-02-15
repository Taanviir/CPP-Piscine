#include <iostream>
#include "iter.hpp"

template<typename FuncType>
void print(FuncType const &x) {
    std::cout << x << std::endl;
}

int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};

    iter(intArray, 5, print<int>);
    iter(floatArray, 5, print<float>);
    iter(stringArray, 5, print<std::string>);

    return 0;
}
