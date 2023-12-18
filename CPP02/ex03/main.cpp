#include "Point.hpp"

int main(void) {
	
	Point a(1, 1);
	std::cout << "a: " << a << std::endl;
	Point b(2, 5);
	std::cout << "b: " << b << std::endl;
	Point c(5, 3);
	std::cout << "c: " << c << std::endl;

	Point point(2, 2);
	std::cout << "P: " << point << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return 0;
}
