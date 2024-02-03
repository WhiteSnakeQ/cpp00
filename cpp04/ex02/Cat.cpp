#include "Cat.hpp"

Cat::Cat( void ) : A_Animal("Cat")
{
	_brain = new Brain();
	std::cout << _type << " constructor called" << std::endl;
}

Cat::~Cat()
{
	if (_brain)
		delete(_brain);
	std::cout << _type << " Destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meaw" << std::endl;
}

Cat	&Cat::operator=( Cat const *copy )
{
	std::cout << _type << " Operator \"=\" called" << std::endl;
	if (_brain)
		delete (_brain);
	_brain = new Brain(copy->getBrain());
	return (*this);
}

Brain	*Cat::getBrain( void ) const
{
	return (_brain);
}
