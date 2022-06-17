#include "span.hpp"

int	main(void)
{
	{
		std::cout << "=====Subject=====" << std::endl;
		span	sp = span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;

		std::cout << "shortest span\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span \t" << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "=====Exceptions=====" << std::endl;
		span	sp = span(3);

		sp.addNumber(5);
		std::cout << sp << std::endl;

		try
		{
			std::cout << "shortest span\t" << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "?\t";
			std::cerr << e.what() << std::endl;
		}

		try
		{		
			std::cout << "longest span \t" << sp.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "?\t";
			std::cerr << e.what() << std::endl;
		}

		try
		{	
			sp.addNumber(6012);
			std::cout << sp << std::endl;
			sp.addNumber(-791);
			std::cout << sp << std::endl;
			sp.addNumber(832);
			std::cout << sp << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "shortest span\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span \t" << sp.longestSpan() << std::endl;
	}
	return (0);
}

void	span::printData(std::ostream &o, const unsigned int max) const
{
	o << "[ ";
	for (unsigned int i = 0; i < max && i < _stored; i++)
		o << _vec[i] << " ";
	if (_stored > max)
		o << "... " << _vec[_stored - 1] << " ";
	o << "] (" << _stored << "/" << _size << ")";
}

std::ostream	&operator<<(std::ostream &o, const span &span)
{
	span.printData(o);
	return (o);
};