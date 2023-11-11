#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
	std::cout << "Default Dog constructor called." << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
	*this = copy;
	std::cout << "Dog Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}