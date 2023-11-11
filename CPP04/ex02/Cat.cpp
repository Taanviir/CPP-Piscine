#include "Cat.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>

Cat::Cat(): AAnimal() {
	std::cout << "Default Cat constructor called." << std::endl;
	type = "Cat";
	_brains = new Brain();
	if (!_brains) {
		perror("Brain allocation failed.");
		exit(1);
	}
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete _brains;
}

Cat::Cat(const Cat& copy): AAnimal(copy) {
	*this = copy;
	std::cout << "Cat Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
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

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}