#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& src) {
	*this = src;
}

Fixed::Fixed(const int value) {
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	this->_fixedPointValue = (int) roundf(floatValue * (1 << this->_fractionalBits));
}

int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return (this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const {
	return (int)(this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue) {
	out << fixedValue.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed& fixedValue) {
	this->_fixedPointValue = fixedValue.getRawBits();
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
	return (this->_fixedPointValue + fixedValue.getRawBits());
}

Fixed Fixed::operator-(const Fixed& fixedValue) {
	return (this->_fixedPointValue - fixedValue.getRawBits());
}

Fixed Fixed::operator*(const Fixed& fixedValue) {
	return (this->_fixedPointValue * fixedValue.getRawBits());
}

Fixed Fixed::operator/(const Fixed& fixedValue) {
	return (this->_fixedPointValue / fixedValue.getRawBits());
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