#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "Default Wrong Cat constructor called." << std::endl;
	_type = "Wrong Cat";
}

WrongCat::~WrongCat() {
	std::cout << "Wrong Cat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy) {
	std::cout << "Wrong Cat copy constructor called." << std::endl;
	this->_type = copy._type;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "Wrong Cat copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}