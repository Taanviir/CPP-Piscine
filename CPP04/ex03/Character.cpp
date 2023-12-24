#include "Character.hpp"
#include <iostream>

Character::Character() {
	DEBUG_MESSAGE("Character default constructor called", WHITE);
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

Character::~Character() {
	DEBUG_MESSAGE("Character destructor called", WHITE);
}

Character::Character(const Character& copy) {
	DEBUG_MESSAGE("Character copy constructor called", WHITE);
	this->_name = copy._name;
}

Character::Character(std::string const* name) {
	if (!name || (*name).empty()) {
		DEBUG_MESSAGE("Character constructor called for Invalid name, name set to \"No Name\"", WHITE);
		_name = "No Name";
		return;
	}
	DEBUG_MESSAGE("Character constructor called for name " << *name, WHITE);
	this->_name = *name;
}

Character::Character(std::string const& name) {
	DEBUG_MESSAGE("Character constructor called for " << name, WHITE);
	if (name.empty()) {
		DEBUG_MESSAGE("Invalid name entered, name set to \"No Name\"", WHITE);
		_name = "No Name";
		return;
	}
	this->_name = name;
}

Character& Character::operator=(const Character& copy) {
	DEBUG_MESSAGE("Character assignment operator called", WHITE);
	this->_name = copy._name;
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << RED << "Invalid materia entered!" << WHITE << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			std::cout << "Materia equipped: " << WHITE_B << m->getType() << WHITE << std::endl;
			return;
		}
	}
	std::cout << RED << "No empty slots available" << WHITE << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << RED << "Invalid index entered!" << std::endl;
		return;
	}
	if (!_materias[idx]) {
		std::cout << RED << "No materia equipped at index " << idx << std::endl;
		return;
	}
	_materias[idx] = NULL;
	std::cout << GRAY << "Materia at index " << idx << " unequipped" << WHITE << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << RED << "Invalid index entered!" << std::endl;
		return;
	}
	if (!_materias[idx]) {
		std::cout << RED << "No materia equipped at index " << idx << std::endl;
		return;
	}
	_materias[idx]->use(target);
}
