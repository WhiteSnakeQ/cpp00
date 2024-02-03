#pragma once

#include "iostream"

class A_Animal
{
protected:
	std::string		_type;
public:
	A_Animal( void );
	A_Animal( std::string type );
	virtual ~A_Animal();
	void virtual	makeSound( void ) const;
	void			setType( std::string type );
	std::string		getType( void ) const;
};
