#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(int argc, char const **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./animalSounds [1|2]" << std::endl;
        return 1;
    }
    if (argv[1][0] == '1') {
        const Animal* meta = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        std::cout << std::endl;
        std::cout << meta->getType() << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;
        std::cout << std::endl;
        cat->makeSound(); //will output the cat sound!
        dog->makeSound();
        meta->makeSound();
        std::cout << std::endl;
        delete meta;
        delete cat;
        delete dog;
    } else {
        const WrongAnimal* wrongCat = new WrongCat();
        std::cout << std::endl;
        std::cout << wrongCat->getType() << std::endl;
        std::cout << std::endl;
        wrongCat->makeSound();
        std::cout << std::endl;
        delete wrongCat;
    }

    return 0;
}
