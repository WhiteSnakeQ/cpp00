#pragma once

#include "Builder.hpp"
#include <iostream>

class PhoneBook
{
private:
	Contact _contacts[8];
	Builder	_builder;
	size_t	_index;
	void	choise_index(void);
	void	increase_index(void);
	void	search(void);
	void	add(void);
	void	add(Contact cont);
	void	fill_all(void);
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	start(void);
};
