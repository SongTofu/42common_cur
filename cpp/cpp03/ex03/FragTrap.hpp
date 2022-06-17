#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const& src);
		~FragTrap(void);

		FragTrap&	operator=(FragTrap const& rhs);

		void	attack(std::string const& target);
		void	highFivesGuys(void);
};

#endif