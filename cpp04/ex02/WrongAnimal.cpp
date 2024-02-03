#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "-" )
{
	std::cout << "Animal Default constractor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
	std::cout << "Animal constractor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal Destractor called" << std::endl;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound" << std::endl;
}

void	WrongAnimal::setType( std::string type )
{
	_type = type;
}

std::string	WrongAnimal::getType( void ) const
{
	return (_type);
}
