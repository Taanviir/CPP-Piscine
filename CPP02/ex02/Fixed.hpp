#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:
	Fixed(): _fixedPointValue(0) {};
	Fixed(const Fixed& src): _fixedPointValue(src._fixedPointValue) {};
	Fixed(const int value);
	Fixed(const float floatValue);
	~Fixed() {};

	Fixed& operator=(const Fixed& fixedValue);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& fixedValue) const;
	bool operator<(const Fixed& fixedValue) const;
	bool operator>=(const Fixed& fixedValue) const;
	bool operator<=(const Fixed& fixedValue) const;
	bool operator==(const Fixed& fixedValue) const;
	bool operator!=(const Fixed& fixedValue) const;

	Fixed operator+(const Fixed& fixedValue);
	Fixed operator-(const Fixed& fixedValue);
	Fixed operator*(const Fixed& fixedValue);
	Fixed operator/(const Fixed& fixedValue);

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue);

#endif