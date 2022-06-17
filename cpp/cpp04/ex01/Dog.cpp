#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	this->printIdeas();
	std::cout << "[Dog]" << " constructor called." << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other), _brain(new Brain(*(other._brain)))
{
	std::cout << "[Dog]" << " constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog]" << " destructor called." << std::endl;
	delete _brain;
}

Dog&	Dog::operator=(Dog const& other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = other._brain;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "woof!! woof!!" <<  std::endl;
}

void	Dog::printIdeas() const
{
	this->_brain->printIdeas();
	std::cout << "=>Address " << &this->_brain << std::endl;
}