#pragma once

#include "iostream"
#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point( void);
	Point( Fixed const x, Fixed const y );
	Point( Point const &point );
	Point	&operator=( Point const &src );
	float	get_x( void ) const;
	float	get_y( void ) const;
	~Point();
};

std::ostream	&operator<<( std::ostream &o, Point const &a );