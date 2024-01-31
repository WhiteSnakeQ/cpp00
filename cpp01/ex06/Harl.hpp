#pragma once

#include "iostream"

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	void	push_messge( int i );
public:
	Harl(void);
	~Harl();
	void	complain( std::string level );
};
