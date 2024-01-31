#include "Fixed.hpp"

Fixed::Fixed( void ) : _fix(0)
{
	std::cout << "Standart constractor called" << std::endl;
}

Fixed::Fixed( Fixed &a )
{
	std::cout << "Copy constractor called" << std::endl;
	*this = a;
}

Fixed &Fixed::operator=( Fixed &src )
{
	std::cout << "Operator \"=\" called" << std::endl;
	if (&src != this)
		this->_fix = src.getRawBit();
	return (*this);
}

int	Fixed::getRawBit( void )
{
	std::cout << "getRawBit called" << std::endl;
	return (_fix);
}

void	Fixed::setRawBit( int a )
{
	std::cout << "setRawBit called" << std::endl;
	_fix = a;
}

Fixed::~Fixed( void )
{
	std::cout << "Standart destractor called" << std::endl;
}

const int	Fixed::C_INT = 8;