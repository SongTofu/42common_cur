#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "[Dog]" << " constructor called." << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other)
{
	std::cout << "[Dog]" << " constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog]" << " destructor called." << std::endl;
}

Dog&	Dog::operator=(Dog const& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "woof!! woof!!" <<  std::endl;
}