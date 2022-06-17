#include "Character.hpp"

Character::Character() : _name("def")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character::Character(Character const& other)
{
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

Character& Character::operator=(Character const& other)
{
	if (this != &other)
	{
		this->_name = other._name;
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

std::string	const& Character::getName() const
{
	return(this->_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;
	if (!m)
	{
		std::cout << this->_name << " tried to equip nothing and it did nothing" << std::endl;
		return ;
	}
	while (this->_inventory[i] && i < 4)
		i++;
	if (i == 4)
	{
		std::cout << this->_name << " can't equip more than 4 Materia" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	std::cout << this->_name << " equipped materia " << m->getType() << " in slot " << i << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << _name << " tried to unequip nothing at slot " << idx << " and it did nothing" << std::endl;
	else if (!(this->_inventory[idx]))
		std::cout << _name << " Has nothing equipped at slot " << idx << " so he can't unequip it" << std::endl;
	else
	{
		std::cout << _name << " unequipped " << this->_inventory[idx]->getType() \
		<< " at slot " << idx << std::endl;
		this->_inventory[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !(this->_inventory[idx]))
	{
		std::cout << "Nothing found to use at index " << idx << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}