#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	// shifting int value by 8 bits to the left thus converting it to fixed point format
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	// shifting float value by 8 bits to the left thus converting it to fixed point format
	_rawBits = (int) roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat(void) const {
	// dividing fixed point value by 2^8 (256.0) to retrieve the float part
	return ((_rawBits) / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	// shifting fixed point value by 8 bits to the right to retrieve the integer part
	return ((int)(_rawBits >> _fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& other) {
	out << other.toFloat();
	return out;
}