#ifndef SAPN_HPP
# define SAPN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class span
{
private:
	unsigned int	_size;
	unsigned int	_stored;
	std::vector<int>	_vec;
	span();
public:
	span(unsigned int n);
	span(span const& other);
	span&	operator=(span const& other);

	void	addNumber(const int n);
	int		shortestSpan() const;
	int		longestSpan() const;
	~span();

	void	printData(std::ostream &o, const unsigned int max = 10) const;
	class alreadyFull : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				 return ("Span::Exception : data is full");
			}
	};
	class notEnoughNumbers : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				 return ("Span::Exception : not enough numbers");
			}
	};

};

std::ostream & operator<<(std::ostream & o, span const& span);

#endif