#include "Karen.hpp"

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		return (-1);
	Karen karen;
	std::string level = (std::string)av[1];

	karen.complain(level);
}