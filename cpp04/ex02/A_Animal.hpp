#pragma once

#include "iostream"
#include "Brain.hpp"

class A_Animal
{
protected:
	std::string		_type;
	A_Animal( void );
	A_Animal( std::string type );
public:
	virtual ~A_Animal();
	void virtual	makeSound( void ) const;
	void			setType( std::string type );
	A_Animal virtual	&operator=( A_Animal const *copy );
	std::string		getType( void ) const;
};
