#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
	DEBUG_MESSAGE("Ice default constructor called", BLUE);
	_type = "ice";
}

Ice::~Ice() {
	DEBUG_MESSAGE("Ice constructor called", BLUE);
}

Ice::Ice(const Ice& copy): AMateria(copy) {
	DEBUG_MESSAGE("Ice copy constructor called", BLUE);
	this->_type = copy._type;
}

Ice& Ice::operator=(const Ice& copy) {
	DEBUG_MESSAGE("Ice copy assignment operator called", BLUE);
	this->_type = copy._type;
	return *this;
}

AMateria* Ice::clone() const {
	DEBUG_MESSAGE("Cloning Ice...", BLUE);
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << WHITE << std::endl;
}
