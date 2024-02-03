#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materials[4];
public:
	MateriaSource( void );
	~MateriaSource();
	void		learnMateria( AMateria* );
	AMateria	*createMateria( std::string const &type );
};
