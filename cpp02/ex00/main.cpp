#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed	b( a );
	Fixed	c;

	c = b;

	std::cout << a.getRawBit() << std::endl;
	std::cout << b.getRawBit() << std::endl;
	std::cout << c.getRawBit() << std::endl;
}