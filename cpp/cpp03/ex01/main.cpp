#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	trap0;
	ScavTrap	trap1("Name");
	ScavTrap	trap2(trap0);

	std::cout << std::endl;
	trap0.attack("target");
	std::cout << std::endl;
	trap1.takeDamage(2);
	trap2.beRepaired(5);
	std::cout << std::endl;
	trap0.guardGate();
	std::cout << std::endl;
	return (0);
}