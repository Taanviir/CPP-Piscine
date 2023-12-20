#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal() {
	std::cout << "Default Cat constructor called." << std::endl;
	_type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy) {
	std::cout << "Cat Copy constructor called." << std::endl;
	_type = copy._type;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}