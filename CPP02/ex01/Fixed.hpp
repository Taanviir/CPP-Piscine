#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float floatValue);
	~Fixed();

	Fixed& operator=(const Fixed& copy);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _rawBits;
	static const int _fractionalBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue);

#endif