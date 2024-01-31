#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
}

Point::Point( Fixed const x, Fixed const y ) : _x(x.toFloat()), _y(y.toFloat())
{
}

Point::Point( Point	const &point ) : _x(point.get_x()), _y(point.get_y())
{
}

Point::~Point()
{
}

Point	&Point::operator=( Point const &point )
{
	(void)point;
	return (*this);
}

float	Point::get_x( void ) const
{
	return (_x.toFloat());
}

float	Point::get_y( void ) const
{
	return (_y.toFloat());
}

std::ostream	&operator<<( std::ostream &o, Point const &a )
{
	// std::cout << "Operator \"<<\" called" << std::endl;
	o << "Point(" << a.get_x() << ", " << a.get_y() << ")";
	return (o);
}
