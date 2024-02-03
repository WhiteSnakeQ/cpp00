#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	~WrongCat();
	void  makeSound( void ) const;
};
