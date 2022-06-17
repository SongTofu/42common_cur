#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>

Base	*generate()
{
	int	randInt;

	randInt = std::rand() % 3;

	if (randInt == 0)
		return (new A());
	else if (randInt == 1)
		return (new B());
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) {}
}

int	main()
{
	srand(time(NULL));
	Base	*p = generate();

	identify(p);
	identify(*p);
	delete p;
	return (0);
}