#include "Zombie.hpp"

void	Zombie::announce() const
{
	std::cout << _name << " " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << "R.I.P :: " << _name << std::endl;
}

void	Zombie::set_name(std::string new_name)
{
	this->_name = new_name;
}