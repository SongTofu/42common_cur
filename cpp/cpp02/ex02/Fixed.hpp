#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_fixedPointValue;
	static int const	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const int value_int);
	Fixed(const float value_float);
	~Fixed();
	Fixed(const Fixed& copy);
	Fixed&	operator = (const Fixed &op);
	int	getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int	toInt() const;
	Fixed operator+(const Fixed &src) const;
	Fixed operator-(const Fixed &src) const;
	Fixed operator*(const Fixed &src) const;
	Fixed operator/(const Fixed &src) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	bool operator==(const Fixed &op) const;
	bool operator!=(const Fixed &op) const;
	bool operator<(const Fixed &op) const;
	bool operator<=(const Fixed &op) const;
	bool operator>(const Fixed &op) const;
	bool operator>=(const Fixed &op) const;

	static Fixed const &min(const Fixed &a, const Fixed &b);
	static Fixed const &max(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif