#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_materia[i])
			delete _materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (copy._materia[i])
			this->_materia[i] = (copy._materia[i])->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	std::cout << "MateriaSource assignation operator called" << std::endl;
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
	std::cout << "Materia learned: " << materia->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] && _materia[i]->getType() == type) {
			std::cout << "Materia created: " << type << std::endl;
			return _materia[i]->clone();
		}
	}
	std::cout << "Materia not found: " << type << std::endl;
	return NULL;
}
