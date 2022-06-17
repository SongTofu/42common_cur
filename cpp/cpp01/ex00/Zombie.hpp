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
	~Zombie();
	void	announce() const;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif