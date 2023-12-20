#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Default Animal constructor called." << std::endl;
	_type = "none";
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal Copy constructor called." << std::endl;
	_type = copy._type;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

std::string Animal::getType(void) const {
	return _type;
}

void Animal::makeSound(void) const {
	std::cout << "Generic Animal sound!" << std::endl;
}