#ifndef ZOMEBIE_HPP
# define ZOMEBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void	announce() const;
	void	set_name(std::string new_name);
};

Zombie* zombieHorde( int N, std::string name );
void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif