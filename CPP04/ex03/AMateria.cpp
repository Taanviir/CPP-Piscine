#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {
	std::cout << "AMateria default constructor called" << std::endl;
	_type = "No Type";
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy) {
	std::cout << "AMateria copy constructor called" << std::endl;
	this->_type = copy._type;
}

AMateria::AMateria(std::string const* type) {
	if (!type || (*type).empty()) {
		std::cout << "AMateria constructor called for Invalid type, type set to \"No Type\"" << std::endl;
		_type = "No Type";
		return;
	}
	std::cout << "AMateria constructor called for type " << *type << std::endl;
	this->_type = *type;
}

AMateria::AMateria(std::string const& type) {
	std::cout << "AMateria constructor called for " << type << std::endl;
	if (type.empty()) {
		std::cout << "Invalid type entered, type set to \"No Type\"" << std::endl;
		_type = "No Type";
		return;
	}
	this->_type = type;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	std::cout << "AMateria assignment operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* abstract use on target " << target.getName() << " *" << std::endl;
}
