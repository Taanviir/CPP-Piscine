#include "Cat.hpp"
#include <iostream>

Cat::Cat(): AAnimal() {
	std::cout << "Default Cat constructor called." << std::endl;
	_type = "Cat";
	_brains = new Brain();
	if (!_brains)
		throw std::runtime_error("Brain allocation failed.");
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete _brains;
}

Cat::Cat(const Cat& copy): AAnimal(copy) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->_type = copy._type;
	this->_brains = new Brain();
	if (!this->_brains)
		throw std::runtime_error("Brain allocation failed.");
	*this->_brains = *copy._brains;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this == &copy) return *this;
	this->_type = copy._type;
	this->_brains = new Brain();
	if (!this->_brains)
		throw std::runtime_error("Brain allocation failed.");
	*this->_brains = *copy._brains;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}