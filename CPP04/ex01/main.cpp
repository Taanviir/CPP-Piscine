#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; //should not create a leak
    delete i;

    // proof of deep copy
    Dog dog1;
    Dog dog2 = dog1;

    // array of animals, half dogs, half cats
    const Animal *animals[4];
    for (int i = 0; i < 4; i++) {
        if (i < 10)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

    return 0;
}
