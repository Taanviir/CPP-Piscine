#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
	_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}

Fixed::Fixed(const int value) {
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	_fixedPointValue = (int) roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return (_fixedPointValue / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	return (int)(_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue) {
	out << fixedValue.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed& copy) {
	if (this != &copy)
		this->_fixedPointValue = copy.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& fixedValue) const {
	return (this->_fixedPointValue > fixedValue.getRawBits());
}

bool Fixed::operator<(const Fixed& fixedValue) const {
	return (this->_fixedPointValue < fixedValue.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixedValue) const {
	return (this->_fixedPointValue >= fixedValue.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixedValue) const {
	return (this->_fixedPointValue <= fixedValue.getRawBits());
}

bool Fixed::operator==(const Fixed& fixedValue) const {
	return (this->_fixedPointValue == fixedValue.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixedValue) const {
	return (this->_fixedPointValue != fixedValue.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixedValue) {
	return Fixed(_fixedPointValue + fixedValue.getRawBits());
}

Fixed Fixed::operator-(const Fixed& fixedValue) {
	return Fixed(_fixedPointValue - fixedValue.getRawBits());
}

Fixed Fixed::operator*(const Fixed& fixedValue) {
	return (this->toFloat() * fixedValue.toFloat()); //!
}

Fixed Fixed::operator/(const Fixed& fixedValue) {
	if (fixedValue.getRawBits() == 0) {
		std::cout << "Error: Cannot divide by zero!" << std::endl;
		return 0;
	}
	return (this->toFloat() / fixedValue.toFloat()); //!
}

Fixed& Fixed::operator++(void) {
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++((*this));
	return tmp;
}

Fixed& Fixed::operator--(void) {
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}