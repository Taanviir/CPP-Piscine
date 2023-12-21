#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "Default WrongCat constructor called." << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	this->_type = copy._type;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}