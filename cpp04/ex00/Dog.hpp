#pragma once

#include "Animal.hpp"

class Dog : public A_Animal
{
public:
	Dog( void );
	~Dog();
	void  makeSound( void ) const;
};
