#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

static void	display(int a)
{
	std::cout << a << " ";
}

template<typename T> void	executeTest()
{
	int	fill[7];
	for (int i = 0; i < 7; i++)
		fill[i] = std::rand() % 100;

	std::cout << "Init <int>" << std::endl;
	T	lst(fill, fill + 7);
	std::for_each(lst.begin(), lst.end(), display);
	std::cout << std::endl;

	std::cout << "Item found in <int>" << std::endl;
	std::cout << "value at easyfind(container, " << fill[3] << ") is " << *(easyfind(lst, fill[3])) << std::endl;

	std::cout << "Print <int> from the found iterator" << std::endl;
	std::for_each(easyfind(lst, fill[3]), lst.end(), display);
	std::cout << std::endl;

	std::cout << "Item can't be found in <int>" << std::endl;
	std::cout << "easyfind(container, 101) == container.end() ? " << ((lst.end() == easyfind(lst, 101)) ? "true" : "false") << std::endl;
}

int	main(void)
{
	srand(time(NULL));

	std::cout << "=====LIST=====" << std::endl;
	executeTest< std::list<int> >();
	std::cout << "=====VECTOR=====" << std::endl;
	executeTest< std::vector<int> >();
	std::cout << "=====DEQUE=====" << std::endl;
	executeTest< std::deque<int> >();
	
	return (0);
}