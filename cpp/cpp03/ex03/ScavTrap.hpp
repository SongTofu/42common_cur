#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:
	/* data */
public:
	ScavTrap();
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const & other);
	~ScavTrap();
	
	ScavTrap&	operator=(ScavTrap const& other);

	void	attack(std::string const &target);
	void	guardGate();
};

#endif
