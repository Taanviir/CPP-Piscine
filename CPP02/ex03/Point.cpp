#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& copy) {
	*this = copy;
}

Point::~Point() {}

Point& Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return (*this);
}

const Fixed& Point::getX(void) const {
	return (_x);
}

const Fixed& Point::getY(void) const {
	return (_y);
}