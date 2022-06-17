#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value_int)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value_int << this->_fractionalBits;
}

Fixed::Fixed(const float value_float)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)(roundf(value_float * (1 << this->_fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
}

Fixed&	Fixed::operator = (const Fixed &op)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->_fixedPointValue = op.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
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
