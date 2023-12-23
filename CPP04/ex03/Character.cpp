#include "Character.hpp"
#include <iostream>

Character::Character() {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& copy) {
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = copy._name;
}

Character::Character(std::string const* name) {
	if (!name || (*name).empty()) {
		std::cout << "Character constructor called for Invalid name, name set to \"No Name\"" << std::endl;
		_name = "No Name";
		return;
	}
	std::cout << "Character constructor called for name " << *name << std::endl;
	this->_name = *name;
}

Character::Character(std::string const& name) {
	std::cout << "Character constructor called for " << name << std::endl;
	if (name.empty()) {
		std::cout << "Invalid name entered, name set to \"No Name\"" << std::endl;
		_name = "No Name";
		return;
	}
	this->_name = name;
}

Character& Character::operator=(const Character& copy) {
	std::cout << "Character assignment operator called" << std::endl;
	this->_name = copy._name;
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Invalid materia entered!" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			std::cout << "Materia " << m->getType() << " equipped" << std::endl;
			return;
		}
	}
	std::cout << "No empty slots available" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Invalid index entered!" << std::endl;
		return;
	}
	if (!_materias[idx]) {
		std::cout << "No materia equipped at index " << idx << std::endl;
		return;
	}
	_materias[idx] = NULL;
	std::cout << "Materia at index " << idx << " unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Invalid index entered!" << std::endl;
		return;
	}
	if (!_materias[idx]) {
		std::cout << "No materia equipped at index " << idx << std::endl;
		return;
	}
	_materias[idx]->use(target);
}
