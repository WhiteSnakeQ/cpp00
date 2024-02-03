#pragma once

#include "iostream"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;
public:
	AMateria( std::string const &type );
	virtual ~AMateria( void );
	std::string const &getType( void ) const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter&  target);
};
