#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
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