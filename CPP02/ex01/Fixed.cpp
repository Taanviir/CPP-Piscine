#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
	*this = copy;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	// shifting int value by 8 bits to the left thus converting it to fixed point format
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	// shifting float value by 8 bits to the left thus converting it to fixed point format
	_fixedPointValue = (int) roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPointValue = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	// dividing fixed point value by 2^8 (256.0) to retrieve the float part
	return ((_fixedPointValue) / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	// shifting fixed point value by 8 bits to the right to retrieve the integer part
	return ((int)(_fixedPointValue >> _fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue) {
	out << fixedValue.toFloat();
	return out;
}