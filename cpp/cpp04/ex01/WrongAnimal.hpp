#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const& other);
	virtual ~WrongAnimal();

	WrongAnimal&	operator=(WrongAnimal const& other);

	std::string	getType() const;
	void	makeSound() const;
};

#endif