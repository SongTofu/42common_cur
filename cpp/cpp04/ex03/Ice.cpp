#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const& other)
{
	*this = other;
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(Ice const& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Ice*	Ice::clone() const
{
	return(new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}