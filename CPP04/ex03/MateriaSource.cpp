#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	DEBUG_MESSAGE("MateriaSource default constructor called", GRAY);
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	DEBUG_MESSAGE("MateriaSource destructor called", GRAY);
	for (int i = 0; i < 4; i++) {
		if (_materia[i])
			delete _materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	DEBUG_MESSAGE("MateriaSource copy constructor called", GRAY);
	for (int i = 0; i < 4; i++) {
		if (copy._materia[i])
			this->_materia[i] = (copy._materia[i])->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	DEBUG_MESSAGE("MateriaSource copy assignment operator called", GRAY);
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i])
			delete this->_materia[i];
		if (copy._materia[i])
			this->_materia[i] = (copy._materia[i])->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (!_materia[i]) {
			_materia[i] = materia;
			break;
		}
	}
	std::cout << "Materia learned: " << YELLOW_B << materia->getType() << WHITE << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] && _materia[i]->getType() == type) {
			std::cout << "Materia created: " << YELLOW_B << type << WHITE << std::endl;
			return _materia[i]->clone();
		}
	}
	std::cout << RED << "Materia not found: " << WHITE << type << std::endl;
	return NULL;
}
