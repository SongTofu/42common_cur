#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "[Animal]" << "<" << _type << ">" << " constructor called." << std::endl;
}

Animal::Animal(std::string const& type) : _type(type)
{
	std::cout << "[Animal]" << "<" << _type << ">" << " constructor called." << std::endl;
}

Animal::Animal(Animal const& other)
{
	_type = other._type;
	std::cout << "[Animal]" << "<" << _type << ">" << " copy constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "[Animal]" << " destructor called." << std::endl;
}

Animal	&Animal::operator=(Animal const& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "--UNDEFINED--" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}