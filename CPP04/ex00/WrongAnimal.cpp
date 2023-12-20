#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "Default Wrong Animal constructor called." << std::endl;
	_type = "none";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "Wrong Animal Copy constructor called." << std::endl;
	_type = copy._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << "Wrong Animal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return _type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "Generic Wrong Animal sound!" << std::endl;
}