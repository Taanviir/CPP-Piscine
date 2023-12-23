#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {
	_type = "No Type";
}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& copy) {
	this->_type = copy._type;
}

AMateria::AMateria(std::string const* type) {
	if (!type || (*type).empty()) {
		std::cout << "Invalid type entered, type set to \"No Type\"" << std::endl;
		_type = "No Type";
		return;
	}
	this->_type = *type;
}

AMateria::AMateria(std::string const& type) {
	if (type.empty()) {
		std::cout << "Invalid type entered, type set to \"No Type\"" << std::endl;
		_type = "No Type";
		return;
	}
	this->_type = type;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	this->_type = copy._type;
	return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {

}
