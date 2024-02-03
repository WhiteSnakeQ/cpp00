#include "A_Animal.hpp"

A_Animal::A_Animal( void ) : _type( "-" )
{
	std::cout << "Animal Default constractor called" << std::endl;
}

A_Animal::A_Animal( std::string type ) : _type(type)
{
	std::cout << "Animal constractor called" << std::endl;
}

A_Animal::~A_Animal()
{
	std::cout << "Animal Destractor called" << std::endl;
}

void	A_Animal::makeSound( void ) const
{
	std::cout << "makeSound" << std::endl;
}

void	A_Animal::setType( std::string type )
{
	_type = type;
}

std::string	A_Animal::getType( void ) const
{
	return (_type);
}

A_Animal	&A_Animal::operator=( A_Animal const *copy )
{
	std::cout << "Animal Operator \"=\" called" << std::endl;
	_type = copy->_type;
	return (*this);
}
