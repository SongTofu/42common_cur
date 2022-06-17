#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack_zombie("Stack Zombie");
	Zombie	*heap_zombie = newZombie("Heap Zombie");

	randomChump("Random Chump Zombie");
	delete heap_zombie;
	return (0);
}