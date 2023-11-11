#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("none") {
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal(const Animal& copy) {
	*this = copy;
	std::cout << "Animal Copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	return *this;
}

std::string Animal::getType(void) const {
	return type;
}

void Animal::setType(const std::string& newType) {
	type = newType;
}

void Animal::makeSound(void) const {
	std::cout << "Generic Animal sound!" << std::endl;
}