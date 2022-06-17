#include "span.hpp"

span::span() : _size(0), _stored(0) {}

span::span(unsigned int n) : _size(n), _stored(0)
{
}

span::span(span const& other)
{
	*this = other;
}

span&	span::operator=(span const& other)
{
	if (this != &other)
	{
		_size = other._size;
		_vec.clear();
		copy(other._vec.begin(), other._vec.end(), _vec.begin());
	}
	return (*this);
}
span::~span()
{
	_vec.clear();
}

void	span::addNumber(const int n)
{
	if (_vec.size() >= _size)
		throw (span::alreadyFull());
	_vec.push_back(n);
	_stored++;
}

int		span::shortestSpan() const
{
	int	secMin;
	if (_stored <= 1)
		throw(span::notEnoughNumbers());
	std::vector<int>::const_iterator	minIt = std::min_element(_vec.begin(), _vec.end());
	if (minIt == _vec.begin())
		secMin = *std::min_element(_vec.begin() + 1, _vec.end());
	else if (minIt + 1 == _vec.end())
		secMin = *std::min_element(_vec.begin(), _vec.end() - 1);
	else
		secMin = std::min(*std::min_element(_vec.begin(), minIt - 1), *std::min_element(minIt + 1, _vec.end()));
	return (secMin - *minIt);
}

int		span::longestSpan() const
{
	if (_stored <= 1)
		throw(span::notEnoughNumbers());
	std::vector<int>::const_iterator	minIt = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::const_iterator	maxIt = std::max_element(_vec.begin(), _vec.end());
	return (*maxIt - *minIt);
}
