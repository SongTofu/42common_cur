#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(std::string const& type);
	Animal(Animal const& other);
	virtual ~Animal();

	Animal&	operator=(const Animal& other);
	std::string	getType() const;
	virtual void	makeSound() const = 0;
};

#endif