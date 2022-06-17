#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value_int)
{
	this->_fixedPointValue = value_int << this->_fractionalBits;
}

Fixed::Fixed(const float value_float)
{
	this->_fixedPointValue = (int)(roundf(value_float * (1 << this->_fractionalBits)));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& copy)
{
	this->_fixedPointValue = copy.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed &op)
{
	if (this == &op)
		return (*this);
	this->_fixedPointValue = op.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int	Fixed::toInt() const
{
	return ((int)this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}

Fixed	Fixed::operator+(const Fixed &src) const
{
	Fixed	t;
	t.setRawBits(_fixedPointValue + src.getRawBits());
	return (t);
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	Fixed	t;
	t.setRawBits(_fixedPointValue - src.getRawBits());
	return (t);
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	Fixed t;
	t.setRawBits(_fixedPointValue * src.getRawBits() / (1 << _fractionalBits));
	return (t);
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	Fixed	t;
	t.setRawBits(_fixedPointValue * (1 << _fractionalBits) / src.getRawBits());
	return (t);
}


Fixed	&Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed t(*this);
	_fixedPointValue++;
	return (t);
}

Fixed	&Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed t(*this);
	_fixedPointValue--;
	return (t);
}

bool Fixed::operator<(Fixed const &op) const {return (_fixedPointValue < op.getRawBits());}
bool Fixed::operator>(Fixed const &op) const {return (_fixedPointValue > op.getRawBits());}
bool Fixed::operator<=(Fixed const &op) const {return (_fixedPointValue <= op.getRawBits());}
bool Fixed::operator>=(Fixed const &op) const {return (_fixedPointValue >= op.getRawBits());}
bool Fixed::operator==(Fixed const &op) const {return (_fixedPointValue == op.getRawBits());}
bool Fixed::operator!=(Fixed const &op) const {return (_fixedPointValue != op.getRawBits());}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}