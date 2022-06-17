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
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif