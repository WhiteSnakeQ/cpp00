#pragma once

#include "iostream"
#include "cmath"

class Fixed
{
private:
	int					_fix;
	static const int 	C_INT;
public:
	Fixed( void );
	Fixed( const int a );
	Fixed( const float a );
	Fixed( Fixed const &a );
	Fixed			&operator=( Fixed const &src );
	int				getRawBit( void ) const;
	int				toInt( void ) const;
	float			toFloat( void ) const;
	void			setRawBit( int a );
	~Fixed();
};

std::ostream	&operator<<( std::ostream &o, Fixed const &a );