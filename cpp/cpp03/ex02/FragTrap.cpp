#include "FragTrap.hpp"

#define	HIT_POINTS	100
#define	ENERGY_POINTS	100
#define	ATTACK_DAMAGE	30


FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "FragTrap " << _name << " was born" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "FragTrap " << _name << " was born" << std::endl;
}

FragTrap::FragTrap(FragTrap const& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "FragTrap " << _name << " was copied" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const& other)
{
	std::cout	<< "FragTrap " << _name << " is copied from " << other._name << std::endl;
	if (this == &other)
		return (*this);
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	FragTrap::attack(std::string const& target)
{
	std::cout << "FragTrap " << _name << " attacked " << target \
		<< " causing " << _attackDamage << " points of damage!\n";
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " requested high fives\n";
}