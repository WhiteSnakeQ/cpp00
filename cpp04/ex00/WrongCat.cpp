#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << _type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << _type << " Destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Bark" << std::endl;
}
