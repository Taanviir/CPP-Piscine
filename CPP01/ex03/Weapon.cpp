#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon(void) {
	return;
}

std::string Weapon::getType(void) {
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}