#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	trap0;
	ClapTrap	trap1("Name");
	ClapTrap	trap2(trap0);

	trap0 = trap1;
	std::cout << std::endl;
	trap0.attack("target");
	trap1.takeDamage(2);
	trap2.beRepaired(5);
	std::cout << std::endl;
	return (0);
}