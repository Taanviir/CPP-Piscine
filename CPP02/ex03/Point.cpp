#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& copy): _x(copy._x), _y(copy._y) {}

Point::~Point() {}

Point& Point::operator=(const Point& rhs) {
	if (this == &rhs) return *this;

	this->~Point(); // manually destruct this object
	new (this) Point(rhs); // using placement new syntax to copy-construct new object
	return (*this);
}

const Fixed& Point::getX(void) const {
	return (_x);
}

const Fixed& Point::getY(void) const {
	return (_y);
}