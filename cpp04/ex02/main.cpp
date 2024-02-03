#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Dog *j = new Dog();
	const Cat *i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();

	delete(j);
	delete(i);

	std::cout << "\n\n" << std::endl;

	const A_Animal *list_animal[4];
	for (size_t i = 0; i < 4; i++)
	{
		if (i % 2 == 1)
			list_animal[i] = new Cat();
		else
			list_animal[i] = new Dog();
	}

	std::cout << "\n\n" << std::endl;

	for (size_t i = 0; i < 4; i++)
		delete(list_animal[i]);
	return (0);
}
