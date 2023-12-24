#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
	DEBUG_MESSAGE("Ice default constructor called", CYAN);
	_type = "ice";
}

Ice::~Ice() {
	DEBUG_MESSAGE("Ice constructor called", CYAN);
}

Ice::Ice(const Ice& copy): AMateria(copy) {
	DEBUG_MESSAGE("Ice copy constructor called", CYAN);
	this->_type = copy._type;
}

Ice& Ice::operator=(const Ice& copy) {
	DEBUG_MESSAGE("Ice copy assignment operator called", CYAN);
	this->_type = copy._type;
	return *this;
}

AMateria* Ice::clone() const {
	DEBUG_MESSAGE("Cloning Ice...", CYAN);
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
