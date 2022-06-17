#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
		else
			this->_inventory[i] = 0;
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = 0;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;

	while (this->_inventory[i] && i < 4)
		i++;
	if (i == 4)
	{
		std::cout << "Can't learn more than 4 Materia" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	std::cout << "Materia " << m->getType() << " learned\n";
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4 && this->_inventory[i]; i++)
	{
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << type << " materia does not exit" << std::endl;
	return (NULL);
}