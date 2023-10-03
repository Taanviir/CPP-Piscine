#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const Point& copy);
		Point(const float x, const float y);
		~Point(void);

		Point& operator=(const Point& rhs);

		const Fixed& getX(void) const;
		const Fixed& getY(void) const;

	private:
		const Fixed _x;
		const Fixed _y;
};

#endif