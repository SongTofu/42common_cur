#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap		trap0;
	DiamondTrap		trap1("Name");
	DiamondTrap		trap2(trap0);

	std::cout << "\n";
	trap0.attack("target");
	std::cout << "\n";
	trap1.takeDamage(2);
	trap2.beRepaired(5);
	std::cout << "\n";
	trap0.guardGate();
	std::cout << "\n";
	trap0.highFivesGuys();
	std::cout << "\n";
	trap1.whoAmI();
	std::cout << "\n";
	return (0);
}