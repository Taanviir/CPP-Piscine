#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:
	Fixed();
	Fixed(const Fixed& src);
	Fixed(const int value);
	Fixed(const float floatValue);
	~Fixed();

	Fixed& operator=(const Fixed& rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue);

#endif