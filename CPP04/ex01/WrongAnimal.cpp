#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("none") {
	std::cout << "Default Wrong Animal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	*this = copy;
	std::cout << "Wrong Animal Copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << "Wrong Animal copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "Generic Wrong Animal sound!" << std::endl;
}