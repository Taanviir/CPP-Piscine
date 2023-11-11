#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(): type("none") {
	std::cout << "Default AAnimal constructor called." << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {
	*this = copy;
	std::cout << "AAnimal Copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	return *this;
}

std::string AAnimal::getType(void) const {
	return type;
}

void AAnimal::setType(const std::string& newType) {
	type = newType;
}

void AAnimal::makeSound(void) const {
	std::cout << "Generic AAnimal sound!" << std::endl;
}