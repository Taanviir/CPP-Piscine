#include "Point.hpp"

int main(void) {
	// need a test case to see if the point is inside the triangle
	
	Point a(1, 1);
	Point b(2, 5);
	Point c(5, 3);

	Point point(2, 2);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return 0;
}
