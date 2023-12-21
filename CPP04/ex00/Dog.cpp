#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
	std::cout << "Default Dog constructor called." << std::endl;
	_type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
	std::cout << "Dog copy constructor called." << std::endl;
	_type = copy._type;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}