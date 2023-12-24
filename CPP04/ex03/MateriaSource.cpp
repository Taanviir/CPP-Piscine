#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	DEBUG_MESSAGE("MateriaSource default constructor called", GRAY);
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	DEBUG_MESSAGE("MateriaSource destructor called", GRAY);
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	DEBUG_MESSAGE("MateriaSource copy constructor called", GRAY);
	for (int i = 0; i < 4; i++) {
		if (copy._inventory[i])
			this->_inventory[i] = (copy._inventory[i])->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	DEBUG_MESSAGE("MateriaSource copy assignment operator called", GRAY);
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = (copy._inventory[i])->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			break;
		}
	}
	std::cout << "Materia learned: " << YELLOW_B << materia->getType() << WHITE << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << "Materia created: " << YELLOW_B << type << WHITE << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << RED << "Materia not found: " << WHITE << type << std::endl;
	return NULL;
}
