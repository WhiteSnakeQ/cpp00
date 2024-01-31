#include "Fixed.hpp"

Fixed::Fixed( void ) : _fix(0)
{
	std::cout << "Standart constractor called" << std::endl;
}

Fixed::Fixed( const int a )
{
	std::cout << "int constractor called" << std::endl;
	_fix = a << C_INT;
}

Fixed::Fixed( Fixed const &a )
{
	std::cout << "Copy constractor called" << std::endl;
	*this = a;
}

Fixed::Fixed( const float a )
{
	std::cout << "float constractor called" << std::endl;
	_fix = roundf(a * (1 << C_INT));
}

Fixed &Fixed::operator=( Fixed const &src )
{
	std::cout << "Operator \"=\" called" << std::endl;
	if (&src != this)
		this->_fix = src.getRawBit();
	return (*this);
}

int	Fixed::toInt( void ) const
{
	// std::cout << "toInt called" << std::endl;
	return (_fix >> C_INT);
}

float	Fixed::toFloat( void ) const
{
	// std::cout << "toFloat called" << std::endl;
	return ((float)_fix / (float)(1 << C_INT));
}

int	Fixed::getRawBit( void ) const
{
	// std::cout << "getRawBit called" << std::endl;
	return (_fix);
}

void	Fixed::setRawBit( int a )
{
	// std::cout << "setRawBit called" << std::endl;
	_fix = a;
}

Fixed::~Fixed( void )
{
	std::cout << "Standart destractor called" << std::endl;
}

const int	Fixed::C_INT= 8;

std::ostream	&operator<<( std::ostream &o, Fixed const &a )
{
	// std::cout << "Operator \"<<\" called" << std::endl;
	o << a.toFloat();
	return (o);
}
