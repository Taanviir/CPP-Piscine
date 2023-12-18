#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed numerator;
	Fixed denominator;

	// Vertices of the triangle
	Fixed Ax = a.getX(), Ay = a.getY();
	Fixed Bx = b.getX(), By = b.getY();
	Fixed Cx = c.getX(), Cy = c.getY();

	// Point to be found
	Fixed Px = point.getX(), Py = point.getY();
	numerator = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
	denominator = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
	Fixed length1(numerator / denominator);

	numerator = Py - Ay - length1 * (By - Ay);
	denominator = Cy - Ay;
	Fixed length2(numerator / denominator);

	return (length1 >= 0 && length2 >= 0 && (length1 + length2) <= 1);
}