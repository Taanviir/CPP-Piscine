#include "Cure.hpp"
#include <iostream>

Cure::Cure() {
	DEBUG_MESSAGE("Cure default constructor called", GREEN);
	_type = "cure";
}

Cure::~Cure() {
	DEBUG_MESSAGE("Cure destructor called", GREEN);
}

Cure::Cure(const Cure& copy): AMateria(copy) {
	DEBUG_MESSAGE("Cure copy constructor called", GREEN);
	this->_type = copy._type;
}

Cure& Cure::operator=(const Cure& copy) {
	DEBUG_MESSAGE("Cure copy assignment operator called", GREEN);
	this->_type = copy._type;
	return *this;
}

AMateria* Cure::clone() const {
	DEBUG_MESSAGE("Cloning Cure...", GREEN);
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << WHITE << std::endl;
}
