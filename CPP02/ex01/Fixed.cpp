#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	// shifting int value by 8 bits to the left thus converting it to fixed point format
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	// shifting float value by 8 bits to the left thus converting it to fixed point format
	this->_fixedPointValue = (int) roundf(floatValue * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	// dividing fixed point value by 256 to get float format
	return (this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const {
	// multiplying fixed point value by 256 to get int format
	return (int)(this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue) {
	out << fixedValue.toFloat();
	return out;
}