#pragma once

#include "Animal.hpp"

class Cat : public A_Animal
{
public:
	Cat( void );
	~Cat();
	void  makeSound( void ) const;
};
