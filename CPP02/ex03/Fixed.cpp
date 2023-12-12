#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
	_rawBits = 0;
}

Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}

Fixed::Fixed(const int value) {
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	_rawBits = (int) roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return (_rawBits / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	return (int)(_rawBits >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue) {
	out << fixedValue.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed& copy) {
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& fixedValue) const {
	return (this->_rawBits > fixedValue.getRawBits());
}

bool Fixed::operator<(const Fixed& fixedValue) const {
	return (this->_rawBits < fixedValue.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixedValue) const {
	return (this->_rawBits >= fixedValue.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixedValue) const {
	return (this->_rawBits <= fixedValue.getRawBits());
}

bool Fixed::operator==(const Fixed& fixedValue) const {
	return (this->_rawBits == fixedValue.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixedValue) const {
	return (this->_rawBits != fixedValue.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixedValue) {
	return Fixed(_rawBits + fixedValue.getRawBits());
}

Fixed Fixed::operator-(const Fixed& fixedValue) {
	return Fixed(_rawBits - fixedValue.getRawBits());
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
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++((*this));
	return tmp;
}

Fixed& Fixed::operator--(void) {
	this->_rawBits--;
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