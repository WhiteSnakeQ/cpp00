#pragma once

#include "A_Animal.hpp"

class Cat : public A_Animal
{
private:
	Brain	*_brain;
public:
	Cat( void );
	~Cat();
	void 	makeSound( void ) const;
	Cat		&operator=( Cat const *copy );
	Brain	*getBrain( void ) const;
};
