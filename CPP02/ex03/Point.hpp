#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const Point& copy);
	Point(const float x, const float y);
	~Point();

	Point& operator=(const Point& rhs);

	const Fixed& getX(void) const;
	const Fixed& getY(void) const;

private:
	const Fixed _x;
	const Fixed _y;
};

#endif