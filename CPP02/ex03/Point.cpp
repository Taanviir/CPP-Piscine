#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::~Point(void) {}

Point& Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return (*this);
}