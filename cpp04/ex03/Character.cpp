#include "Character.hpp"

Character::Character( std::string name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_skills[i] = 0;
	std::cout << "Character " << _name << " constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_skills[i])
			delete(_skills[i]);
	}
	std::cout << "Character " << _name << " destructor called" << std::endl;
}

std::string const	&Character::getName( void ) const
{
	return (_name);
}

void	Character::equip( AMateria *m )
{
	std::cout << "equip " << _name << " called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (!_skills[i])
		{
			_skills[i] = m;
			return ;
		}
	}
	std::cout << "equip " << _name << " canceled" << std::endl;
}

void	Character::unequip( int idx )
{
	std::cout << "unequip " << _name << " called" << std::endl;
	if (idx < 0 || idx > 3)
	{
		std::cout << "unequip " << _name << " canceled" << std::endl;
		return ;
	}
	if (_skills[idx])
	{
		_skills[idx] = NULL;
		for (int i = idx; i < 3; i++)
		{
			_skills[i] = _skills[i + 1];
			_skills[i + 1] = 0;
		}
	}
	else
		std::cout << "unequip " << _name << " inventory full" << std::endl;
}

void	Character::use( int idx, ICharacter &target )
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "use " << _name << " canceled" << std::endl;
		return ;
	}
	if (_skills[idx])
		_skills[idx]->use(target);
}
