#pragma once

#include "iostream"

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain( void );
	Brain( Brain *copy );
	~Brain();
	void getIdeas( Brain &Brain );
};

