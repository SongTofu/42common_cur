#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal]" << " constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "[WrongAnimal]" << "<" << _type << ">" << " constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other) : _type(other._type)
{
	std::cout << "[WrongAnimal]" << " copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal]" << " destructor called." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "--UNDEFINED--" << std::endl;
}
