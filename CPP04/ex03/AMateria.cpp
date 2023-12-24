#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {
	DEBUG_MESSAGE("AMateria default constructor called", MAGENTA);
	_type = "No Type";
}

AMateria::~AMateria() {
	DEBUG_MESSAGE("AMateria destructor called", MAGENTA);
}

AMateria::AMateria(const AMateria& copy) {
	DEBUG_MESSAGE("AMateria copy constructor called", MAGENTA);
	this->_type = copy._type;
}

AMateria::AMateria(std::string const* type) {
	if (!type || (*type).empty()) {
		DEBUG_MESSAGE("AMateria constructor called for Invalid type, type set to \"No Type\"", MAGENTA);
		_type = "No Type";
		return;
	}
	DEBUG_MESSAGE("AMateria constructor called for type " << *type, MAGENTA);
	this->_type = *type;
}

AMateria::AMateria(std::string const& type) {
	DEBUG_MESSAGE("AMateria constructor called for " << type, MAGENTA);
	if (type.empty()) {
		DEBUG_MESSAGE("Invalid type entered, type set to \"No Type\"", MAGENTA);
		_type = "No Type";
		return;
	}
	this->_type = type;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	DEBUG_MESSAGE("AMateria assignment operator called", MAGENTA);
	this->_type = copy._type;
	return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* abstract use on target " << target.getName() << " *" << std::endl;
}
