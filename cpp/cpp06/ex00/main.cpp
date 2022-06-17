#include "Conversion.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Use ./convert [litteralVal]" << std::endl;
		return (1);
	}
	Conversion	c(av[1]);
	std::cout << c;
	return (0);
}