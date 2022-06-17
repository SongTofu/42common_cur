#include "ClapTrap.hpp"

#define	HIT_POINTS	10
#define	ENERGY_POINTS	10
#define	ATTACK_DAMAGE	0

ClapTrap::ClapTrap() : _name("default")
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "CalpTrap " << _name << " was born" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "CalpTrap " << _name << " was born" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << _name << " was copied" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destroyed" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &other)
{
	std::cout	<< "ClapTrap " << _name << " is copied from " << other._name << std::endl;
	if (this == &other)
		return (*this);
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target) const
{
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "CalpTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << _name << "'s hitpoint is " << _hitPoints << "!" << std::endl;
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
	std::cout << "CalpTrap " << _name << " be repaired!" << std::endl;
	std::cout << _name << "'s hitpoint is " << _hitPoints << "!" << std::endl;
}