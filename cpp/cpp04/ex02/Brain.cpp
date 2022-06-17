#include "Brain.hpp"

static std::string	randomString(int size)
{
	const std::string	alphaNum = "abcdefghijklmnopqrstuvwxyz";
	std::string			randomStr = "";

	for (int i = 0; i < size; i++)
		randomStr += alphaNum[std::rand() % alphaNum.size()];
	return (randomStr);
}

Brain::Brain() : _idx(0)
{
	std::cout << "[Brain]" << " default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_ideas[i] = randomString(5);
}

Brain::Brain(Brain const& other) : _idx(0)
{
	std::cout << "[Brain]" << " copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain::~Brain()
{
	std::cout << "[Brain]" <<" destructor called." << std::endl;
}

Brain&	Brain::operator=(Brain const& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(std::string const& idea)
{
	_ideas[_idx++] = idea;
	_idx = _idx % 100;
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < 100 && !_ideas[i].empty(); i++)
		std::cout << "[Brain] [Ideas] " << _ideas[i] << std::endl;
}