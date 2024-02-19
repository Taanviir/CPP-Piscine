#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    srand(time(0));

    int random = rand() % 3;

    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    std::cout << "Generator failed" << std::endl;
    return NULL;
}

void identify(Base* p) {
    try {
        if (dynamic_cast<A *>(p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B *>(p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C *>(p))
            std::cout << "C" << std::endl;
        else
            std::cout << "Unknown Type" << std::endl;
    } catch (std::exception &error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
}

void identify(Base& p) {
    try {
        if (dynamic_cast<A *>(&p)) {
            std::cout << "A" << std::endl;
            return;
        }
    } catch (const std::exception& error) {}
    try {
        if (dynamic_cast<B *>(&p)) {
            std::cout << "B" << std::endl;
            return;
        }
    } catch (const std::exception& error) {}
    try {
        if (dynamic_cast<C *>(&p)) {
            std::cout << "C" << std::endl;
            return;
        }
    } catch (const std::exception& error) {}

    std::cout << "Unknown Type" << std::endl;
}

int main() {
    // testing pointer
    Base *object1 = generate();
    std::cout << "Object type is ";
    identify(object1);
    delete object1;

    // test unknown type
    Base *object2 = new Base();
    std::cout << "Object type is ";
    identify(object2);
    delete object2;

    // testing reference
    Base *object3 = generate();
    Base &ref = *object3;
    std::cout << "Object type is ";
    identify(ref);
    delete object3;

    return 0;
}
