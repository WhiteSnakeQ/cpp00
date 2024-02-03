#pragma once

#include "iostream"

class WrongAnimal
{
protected:
	std::string		_type;
public:
	WrongAnimal( void );
	WrongAnimal( std::string type );
	virtual ~WrongAnimal();
	void virtual	makeSound( void ) const;
	void			setType( std::string type );
	std::string		getType( void ) const;
};
