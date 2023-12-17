#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	// Vertices of the triangle
	Fixed Ax = a.getX(), Ay = a.getY();
	std::cout << "Ax: " << Ax << " Ay: " << Ay << std::endl;
	Fixed Bx = b.getX(), By = b.getY();
	std::cout << "Bx: " << Bx << " By: " << By << std::endl;
	Fixed Cx = c.getX(), Cy = c.getY();
	std::cout << "Cx: " << Cx << " Cy: " << Cy << std::endl;

	// Point to be found
	Fixed Px = point.getX(), Py = point.getY();
	std::cout << "Px: " << Px << " Py: " << Py << std::endl;
	Fixed numerator = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
	Fixed denominator = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
	Fixed length1(numerator / denominator);

	numerator = Py - Ay - length1 * (By - Ay);
	denominator = Cy - Ay;
	Fixed length2(numerator / denominator);

	if (length1 >= 0 && length2 >= 0 && (length1 + length2) <= 1)
		return true;
	return false;
}