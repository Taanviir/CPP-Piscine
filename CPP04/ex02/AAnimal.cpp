#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() {
	std::cout << "Default AAnimal constructor called." << std::endl;
	_type = "No Type";
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	this->_type = copy._type;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

std::string AAnimal::getType(void) const {
	return _type;
}

void AAnimal::setType(const std::string* newType) {
	if (!newType || (*newType).empty()) {
		std::cout << "Invalid type entered, type set to \"No Type\"." << std::endl;
		_type = "No Type";
		return;
	}
	_type = *newType;
}

void AAnimal::setType(const std::string& newType) {
	if (newType.empty()) {
		std::cout << "Invalid type entered, type set to \"No Type\"." << std::endl;
		_type = "No Type";
		return;
	}
	_type = newType;
}
