#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const A_Animal *meta = new A_Animal();
	const Dog *j = new Dog();
	const Cat *i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(j);
	delete(i);

	std::cout << "\n\n" << std::endl;

	const WrongCat *k = new WrongCat();
	std::cout << k->getType() << std::endl;
	k->makeSound();
	delete (k);
	return (0);
}
