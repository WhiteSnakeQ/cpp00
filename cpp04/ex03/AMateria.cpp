#include "AMateria.hpp"

AMateria::AMateria( std::string const &type) : _type(type) {}
AMateria::~AMateria( void ) {}

std::string const &AMateria::getType( void ) const
{
	return (_type);
}

void		AMateria::use(ICharacter&  target)
{
	std::cout << "Spell " << _type << " used on " << target.getName() << std::endl;
}
