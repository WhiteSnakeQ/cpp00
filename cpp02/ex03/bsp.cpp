#include "Point.hpp"
#include "iostream"

class vector_c
{
private:
	float	_dx;
	float	_dy;
public:
	vector_c( float dx = 0, float dy = 0);
	vector_c( Point a, Point b);
	float	get_dx( void );
	float	get_dy( void );
	float	operator*( vector_c &vector );
	~vector_c();
};

vector_c::vector_c( float dx, float dy ) : _dx(dx), _dy(dy)
{
}

vector_c::vector_c( Point a, Point b )
{
	_dx = a.get_x() - b.get_x();
	_dy = a.get_y() - b.get_y();
}

vector_c::~vector_c()
{
}

float vector_c::get_dx( void )
{
	return (_dx);
}

float vector_c::get_dy( void )
{
	return (_dy);
}

float	vector_c::operator*( vector_c &vector )
{
	return (_dx * vector.get_dy() - _dy * vector.get_dx());
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	vector_c 	OA(point, a);
	vector_c	OB(point, b);
	vector_c	OC(point, c);
	vector_c	AB(a, b);
	vector_c	BC(b, c);
	vector_c	CA(c, a);
	
	if ((OA * AB < 0 && OB * BC < 0 && OC * CA < 0) || (OA * AB > 0 && OB * BC > 0 && OC * CA > 0))
		return (true);
	return (false);
}