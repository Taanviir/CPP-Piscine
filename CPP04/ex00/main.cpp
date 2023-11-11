#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongCat* wrongCat = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    wrongCat->makeSound();
    meta->makeSound();
    delete wrongCat;
    delete wrongAnimal;
    delete meta;
    delete i;
    delete j;
    return 0;
}
