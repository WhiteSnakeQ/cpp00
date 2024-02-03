#include "Cat.hpp"

Cat::Cat( void ) : A_Animal("Cat")
{
	std::cout << _type << " constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << _type << " Destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meaw" << std::endl;
}
