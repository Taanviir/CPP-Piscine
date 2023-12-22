#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
	std::cout << "Default Dog constructor called." << std::endl;
	_type = "Dog";
	_brains = new Brain();
	if (!_brains)
		throw std::runtime_error("Brain allocation failed.");
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete _brains;
}

Dog::Dog(const Dog& copy): Animal(copy) {
	std::cout << "Dog copy constructor called." << std::endl;
	this->_type = copy._type;
	this->_brains = new Brain();
	if (!this->_brains)
		throw std::runtime_error("Brain allocation failed.");
	*this->_brains = *copy._brains;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this == &copy)
		return *this;
	this->_type = copy._type;
	this->_brains = new Brain();
	if (!this->_brains)
		throw std::runtime_error("Brain allocation failed.");
	*this->_brains = *copy._brains;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}