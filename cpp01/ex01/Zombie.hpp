#pragma once

#include "iostream"

class Zombie
{
private:
	std::string _name;
public:
	Zombie( void );
	Zombie( std::string name );
	~Zombie();
	void	announce( void );
};
