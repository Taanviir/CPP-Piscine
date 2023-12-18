#include "Fixed.hpp"

int main(void) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// Testing conditionals
	Fixed c(5);
	Fixed d(5);
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;

	// Testing arithmetic
	Fixed e(5);
	Fixed f(2);
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "e + f = " << (e + f) << std::endl;
	std::cout << "e - f = " << (e - f) << std::endl;
	std::cout << "e * f = " << (e * f) << std::endl;
	std::cout << "e / f = " << (e / f) << std::endl;
	
	// Testing min/max
	Fixed g(5);
	Fixed h(2);
	std::cout << "g = " << g << std::endl;
	std::cout << "h = " << h << std::endl;
	std::cout << "min(g, h) = " << Fixed::min(g, h) << std::endl;
	std::cout << "max(g, h) = " << Fixed::max(g, h) << std::endl;

	return 0;
}
