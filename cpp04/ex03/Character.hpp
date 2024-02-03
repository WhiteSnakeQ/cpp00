#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*_skills[4];
public:
	Character( std::string name );
	~Character();
	std::string const	&getName( void ) const;
	void				equip( AMateria *m );
	void				unequip( int idx );
	void				use( int idx, ICharacter &target );
};
