#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal(): type("none") {
	std::cout << "Default Animal constructor called." << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {
	*this = copy;
	std::cout << "Animal Copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	return *this;
}

std::string AAnimal::getType(void) const {
	return type;
}