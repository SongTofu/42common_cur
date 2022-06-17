#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
private:
	std::string	_ideas[100];
	int	_idx;
public:
	Brain();
	Brain(Brain const& other);
	~Brain();

	Brain&	operator=(Brain const& other);

	void	setIdea(std::string const& idea);
	void	printIdeas() const;
};

#endif