#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_fixedPointValue;
	static int const	_fractionalBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& copy);
	Fixed&	operator = (const Fixed &op);
	int	getRawBits() const;
	void	setRawBits(int const raw);
};

#endif