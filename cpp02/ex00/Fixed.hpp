#pragma once

#include "iostream"

class Fixed
{
private:
	int					_fix;
	static const int	C_INT;
public:
	Fixed( void );
	Fixed( Fixed &a );
	Fixed &operator=( Fixed &src);
	int		getRawBit( void );
	void	setRawBit( int a );
	~Fixed();
};
