#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	wrongTest(void)
{
	const WrongAnimal	*w = new WrongCat();

	std::cout << "w is " << w->getType() << " : ";
	w->makeSound();
	
	delete w;
}

void	subjectTest(void)
{
	const Animal	*m = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "j is " << j->getType() << " : ";
	j->makeSound();
	std::cout << "i is " << i->getType() << " : ";
	i->makeSound();
	std::cout << "m is " << m->getType() << " : ";
	m->makeSound();

	delete i;
	delete j;
	delete m;
}

int	main(void)
{
	subjectTest();
	std::cout << std::endl;
	wrongTest();
	return (0);
}