#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
protected:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &other);
	~ClapTrap();

	ClapTrap&	operator=(ClapTrap const &other);

	void	attack(std::string const &target) const;
	void	takeDamage(unsigned int amout);
	void	beRepaired(unsigned int amout);
};

#endif