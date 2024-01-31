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
	Fixed				&operator=( Fixed const &src );
	Fixed				operator+( Fixed const &src );
	Fixed				operator-( Fixed const &src );
	Fixed				operator*( Fixed const &src );
	Fixed				operator/( Fixed const &src );
	Fixed				&operator++( void );
	Fixed				&operator--( void );
	Fixed				operator++( int value );
	Fixed				operator--( int value );
	static Fixed		&min( Fixed &a, Fixed &b );
	static Fixed const	&min( Fixed const &a, Fixed const &b );
	static Fixed		&max( Fixed &a, Fixed &b );
	static Fixed const	&max( Fixed const &a, Fixed const &b );
	bool				operator>( Fixed const &src );
	bool				operator<( Fixed const &src );
	bool				operator>=( Fixed const &src );
	bool				operator<=( Fixed const &src );
	bool				operator==( Fixed const &src );
	bool				operator!=( Fixed const &src );
	int					getRawBit( void ) const;
	int					toInt( void ) const;
	float				toFloat( void ) const;
	void				setRawBit( int a );
	~Fixed();
};

std::ostream	&operator<<( std::ostream &o, Fixed const &a );