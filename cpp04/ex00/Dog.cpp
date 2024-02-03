#include "Dog.hpp"

Dog::Dog( void ) : A_Animal("Dog")
{
	std::cout << _type << " constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << _type << " Destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Bark" << std::endl;
}
