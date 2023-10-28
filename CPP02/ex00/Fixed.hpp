#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed& operator=(const Fixed& copy);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedPointValue;
	static const int _fractionalBits;
};

#endif