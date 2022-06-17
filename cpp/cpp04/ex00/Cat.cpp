#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat]" << " constructor called." << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other)
{
	std::cout << "[Cat]" << " constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat]" << " destructor called." << std::endl;
}

Cat&	Cat::operator=(Cat const& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "meoow!!" <<  std::endl;
}
