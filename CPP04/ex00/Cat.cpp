#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal() {
	std::cout << "Default Cat constructor called." << std::endl;
	type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy) {
	*this = copy;
	std::cout << "Cat Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}