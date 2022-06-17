#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("default")
{
	std::cout << "DiamondTrap " << _name << " was born" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap")
{
	this->_name = name;
	std::cout << "DiamondTrap " << _name << " was born" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other) : ClapTrap(other._name), ScavTrap(other._name + "_scav_trap"), FragTrap(other._name + "_clap_trap")
{
	this->_name = other._name;
	std::cout << "DiamondTrap " << _name << " was copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other)
{
	std::cout	<< "DiamondTrap " << _name << " is copied from " << other._name << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	return(*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destroyed" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << this->_name << std::endl;
	std::cout << "ClapTrap's name is " << ClapTrap::_name << std::endl;
}
