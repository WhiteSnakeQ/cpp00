#pragma once

#include "Animal.hpp"

class Dog : public A_Animal
{
private:
	Brain	*_brain;
public:
	Dog( void );
	~Dog();
	void 	makeSound( void ) const;
	Dog		&operator=( Dog const *copy );
	Brain	*getBrain( void ) const;
};
