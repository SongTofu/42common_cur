#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const& type) : _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const& other) : _type(other._type)
{
}

AMateria&	AMateria::operator=(AMateria const& other)
{
	if (this != & other)
		this->_type = other._type;
	return(*this);
}

std::string const&	AMateria::getType() const
{
	return(this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used on " << target.getName() << std::endl;
}