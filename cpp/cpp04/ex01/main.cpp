#include "Dog.hpp"
#include "Cat.hpp"

static void	testLeaks(void)
{
	std::cout << "==========LEAKS==========" << std::endl;
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	delete dog;
	delete cat;
}

static void	testDeepCopy(void)
{
	std::cout << "==========DEEP COPY==========" << std::endl;
	Dog	dog1;
	Dog	dog2;

	dog1.printIdeas();
	dog2.printIdeas();

	Cat	cat1;
	Cat	cat2(cat1);

	cat1.printIdeas();
	cat2.printIdeas();
}

static void	testSubject(int size)
{
	std::cout << "==========SUBJECT==========" << std::endl;
	Animal	*arrayAnimals[2 * size];

	for (int i = 0; i < size; i++)
	{
		arrayAnimals[i] = new Dog();
		arrayAnimals[size + i] = new Cat();
	}
	for (int i = 0; i < 2 * size; i++)
		delete arrayAnimals[i];
}

int	main(void)
{
	testSubject(3);
	testLeaks();
	testDeepCopy();
	return (0);
}