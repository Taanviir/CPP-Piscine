#include "Cure.hpp"
#include <iostream>

Cure::Cure() {
	std::cout << "Cure default constructor called" << std::endl;
	_type = "cure";
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure& copy): AMateria(copy) {
	this->_type = copy._type;
}

Cure& Cure::operator=(const Cure& copy) {
	this->_type = copy._type;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
