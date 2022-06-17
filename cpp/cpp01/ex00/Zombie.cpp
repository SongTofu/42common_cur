#include "Zombie.hpp"

void	Zombie::announce() const
{
	std::cout << _name << " " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << "R.I.P :: " << _name << std::endl;
}
