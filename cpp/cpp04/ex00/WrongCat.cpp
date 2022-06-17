#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout <<  "[WrongCat]" << " constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal(other)
{
	std::cout << "[WrongCat]" <<" copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat]" <<" destructor called." << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const& other)
{
	if (this != &other)
		this->_type = other._type;
	return(*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat <miao miao>" << std::endl;
}