#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
	std::cout << "Ice default constructor called" << std::endl;
	_type = "ice";
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& copy): AMateria(copy) {
	std::cout << "Ice copy constructor called" << std::endl;
	this->_type = copy._type;
}

Ice& Ice::operator=(const Ice& copy) {
	std::cout << "Ice assignation operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
