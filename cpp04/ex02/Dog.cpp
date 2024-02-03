#include "Dog.hpp"

Dog::Dog( void ) : A_Animal("Dog")
{
	_brain = new Brain();
	std::cout << _type << " constructor called" << std::endl;
}

Dog::~Dog()
{
	delete(_brain);
	std::cout << _type << " Destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Bark" << std::endl;
}

Dog	&Dog::operator=( Dog const *copy )
{
	std::cout << _type << " Operator \"=\" called" << std::endl;
	if (_brain)
		delete (_brain);
	_brain = new Brain(copy->getBrain());
	return (*this);
}

Brain	*Dog::getBrain( void ) const
{
	return (_brain);
}
