#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "Default WrongCat constructor called." << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy) {
	*this = copy;
	std::cout << "WrongCat Copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	this->type = copy.type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}