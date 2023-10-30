#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
	static const int _fractionalBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedValue);

#endif