#pragma once

#include "iostream"

class ClapTrap
{
private:
	std::string _name;
	int			_hp;
	int			_energy;
	int			_damage;
public:
	ClapTrap( std::string name = "default" );
	~ClapTrap();
	void	attack( std::string const &target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};
