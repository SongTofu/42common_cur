#include "ScavTrap.hpp"

#define	HIT_POINTS	100
#define	ENERGY_POINTS	50
#define	ATTACK_DAMAGE	20

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "ScavTrap " << _name << " was born" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "ScavTrap " << _name << " was born" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ScavTrap " << _name << " was copied" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroyed" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& other)
{
	std::cout	<< "ScavTrap " << _name << " is copied from " << other._name << std::endl;
	if (this == &other)
		return (*this);
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	ScavTrap::attack(std::string const& target)
{
	std::cout << "ScavTrap " << _name << " attacked " << target \
		<< " causing " << _attackDamage << " points of damage!\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name \
		<< " have enterred in Gate keeper mode" << std::endl;
}