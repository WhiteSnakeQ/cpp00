#include "Fixed.hpp"

Fixed::Fixed( void ) : _fix(0)
{
	// std::cout << "Standart constractor called" << std::endl;
}

Fixed::Fixed( const int a )
{
	// std::cout << "int constractor called" << std::endl;
	_fix = a << C_INT;
}

Fixed::Fixed( Fixed const &a )
{
	// std::cout << "Copy constractor called" << std::endl;
	*this = a;
}

Fixed::Fixed( const float a )
{
	// std::cout << "float constractor called" << std::endl;
	_fix = roundf(a * (1 << C_INT));
}

Fixed &Fixed::operator=( Fixed const &src )
{
	// std::cout << "Operator \"=\" called" << std::endl;
	if (&src != this)
		this->_fix = src.getRawBit();
	return (*this);
}

Fixed Fixed::operator+( Fixed const &src )
{
	// std::cout << "Operator \"+\" called" << std::endl;
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-( Fixed const &src )
{
	// std::cout << "Operator \"-\" called" << std::endl;
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator/( Fixed const &src )
{
	// std::cout << "Operator \"/\" called" << std::endl;
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed Fixed::operator*( Fixed const &src )
{
	// std::cout << "Operator \"*\" called" << std::endl;
	return (Fixed(this->toFloat() * src.toFloat()));
}

bool Fixed::operator>( Fixed const &src )
{
	// std::cout << "Operator \">\" called" << std::endl;
	if (this->toFloat() > src.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<( Fixed const &src )
{
	// std::cout << "Operator \"<\" called" << std::endl;
	if (this->toInt() < src.toInt())
		return (true);
	return (false);
}

bool Fixed::operator<=( Fixed const &src )
{
	// std::cout << "Operator \"<=\" called" << std::endl;
	if (this->toFloat() <= src.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=( Fixed const &src )
{
	// std::cout << "Operator \">=\" called" << std::endl;
	if (this->toFloat() >= src.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator==( Fixed const &src )
{
	// std::cout << "Operator \"==\" called" << std::endl;
	if (this->toFloat() == src.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=( Fixed const &src )
{
	// std::cout << "Operator \"!=\" called" << std::endl;
	if (this->toInt() != src.toInt())
		return (true);
	return (false);
}

Fixed &Fixed::operator++( void )
{
	// std::cout << "Operator \"++\" called" << std::endl;
	++_fix;
	return (*this);
}

Fixed &Fixed::operator--( void )
{
	// std::cout << "Operator \"--\" called" << std::endl;
	--_fix;
	return (*this);
}

Fixed Fixed::operator++( int value )
{
	// std::cout << "Operator \"++\" called" << std::endl;
	Fixed	tmp;

	if (!value)
		value = 1;
	tmp = *this;
	_fix += value;
	return (tmp);
}

Fixed Fixed::operator--( int value )
{
	// std::cout << "Operator \"--\" called" << std::endl;
	Fixed	tmp;

	if (!value)
		value = 1;
	tmp = *this;
	_fix += value;
	return (tmp);
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	if (a.toFloat() > b.toFloat())
		return (b);
	return (a);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a.toFloat() > b.toFloat())
		return (b);
	return (a);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
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
	// std::cout << "Standart destractor called" << std::endl;
}

const int	Fixed::C_INT= 8;

std::ostream	&operator<<( std::ostream &o, Fixed const &a )
{
	// std::cout << "Operator \"<<\" called" << std::endl;
	o << a.toFloat();
	return (o);
}
