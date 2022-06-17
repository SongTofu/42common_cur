#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	this->printIdeas();
	std::cout << "[Cat]" << " constructor called." << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other), _brain(new Brain(*(other._brain)))
{
	std::cout << "[Cat]" << " constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat]" << " destructor called." << std::endl;
	delete _brain;
}

Cat&	Cat::operator=(Cat const& other)
{
	if (this != &other)
	{
		_brain = other._brain;
		_type = other._type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "meoow!!" <<  std::endl;
}

void	Cat::printIdeas() const
{
	this->_brain->printIdeas();
	std::cout << "=>Address " << &this->_brain << std::endl;
}