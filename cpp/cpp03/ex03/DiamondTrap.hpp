#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	using	FragTrap::_hitPoints;
	using	FragTrap::_attackDamage;
	using	ScavTrap::_energyPoints;
	using	ScavTrap::attack;

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const& other);
	~DiamondTrap();

	DiamondTrap& operator=(DiamondTrap const& other);

	void	whoAmI();
};


#endif