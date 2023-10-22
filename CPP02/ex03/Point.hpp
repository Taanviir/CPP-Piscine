#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
public:
	Point() : _x(0), _y(0) {};
	Point(const Point& copy): _x(copy._x), _y(copy._y) {};
	Point(const float x, const float y): _x(x), _y(y) {};
	~Point() {};

	Point& operator=(const Point& rhs);

	const Fixed& getX(void) const;
	const Fixed& getY(void) const;

private:
	const Fixed _x;
	const Fixed _y;
};

#endif