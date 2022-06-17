#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	/* data */
public:
	WrongCat();
	WrongCat(WrongCat const& other);
	~WrongCat();

	WrongCat&	operator=(WrongCat const& other);
	void	makeSound() const;
};

#endif