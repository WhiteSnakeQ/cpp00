#include "Weapon.hpp"

Weapon::Weapon( void ) : _type("undef")
{
}

Weapon::Weapon( std::string type ) : _type(type)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType( std::string type )
{
	_type = type;
}

std::string	&Weapon::getType( void )
{
	return (_type);
}
