#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	trap0;
	FragTrap	trap1("Name");
	FragTrap	trap2(trap0);

	std::cout << std::endl;
	trap0.attack("target");
	std::cout << std::endl;
	trap1.takeDamage(2);
	trap2.beRepaired(5);
	std::cout << std::endl;
	trap0.highFivesGuys();
	std::cout << std::endl;
	return (0);
}