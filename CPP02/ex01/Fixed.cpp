#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src): _fixedPointValue(src._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
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

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	// dividing fixed point value by 256 to get float format
	return (_fixedPointValue / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	// multiplying fixed point value by 256 to get int format
	return (int)(_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue) {
	out << fixedValue.toFloat();
	return out;
}