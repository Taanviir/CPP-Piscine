#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete i;
    delete j; //should not create a leak
    std::cout << std::endl << std::endl;

    // proof of deep copy
    Dog dog1;
    std::cout << "Dog1: ";
    dog1.makeSound();
    std::cout << "\nDog1 Type: " << dog1.getType() << std::endl;
    // new dog
    Dog dog2 = dog1;
    std::cout << "\nDog2 Type: " << dog2.getType() << std::endl;
    // modifying dog1's type
    dog1.setType("Modified Dog");
    // final results
    std::cout << "\nDog1 New Type: " << dog1.getType() << std::endl;
    std::cout << "\nDog2 type: " << dog2.getType() << std::endl << std::endl;

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
