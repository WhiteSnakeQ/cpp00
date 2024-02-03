#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	~Ice();
	AMateria	*clone() const;
	void		use(ICharacter&  target);
};

