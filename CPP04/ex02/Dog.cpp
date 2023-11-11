#include "Dog.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>

Dog::Dog(): AAnimal() {
	std::cout << "Default Dog constructor called." << std::endl;
	type = "Dog";
	_brains = new Brain();
	if (!_brains) {
		perror("Brain allocation failed.");
		exit(1);
	}
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete _brains;
}

Dog::Dog(const Dog& copy): AAnimal(copy) {
	*this = copy;
	std::cout << "Dog Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	this->_brains = new Brain();
	if (!this->_brains) {
		perror("Brain allocation failed.");
		exit(1);
	}
	*this->_brains = *copy._brains;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}