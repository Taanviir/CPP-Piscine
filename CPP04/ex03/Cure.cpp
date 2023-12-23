#include "Cure.hpp"
#include <iostream>

Cure::Cure() {}

Cure::~Cure() {}

Cure::Cure(const Cure& copy) {
	this->_type = copy._type;
}

Cure& Cure::operator=(const Cure& copy) {
	this->_type = copy._type;
	return *this;
}

AMateria* Cure::clone() const {
		
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
