#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure( void );
	~Cure();
	AMateria	*clone() const;
	void		use(ICharacter&  target);
};

