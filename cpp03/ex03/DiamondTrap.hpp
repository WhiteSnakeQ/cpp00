#pragma once

#include "iostream"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;
public:
	DiamondTrap( std::string name );
	~DiamondTrap();
	void	attack( std::string const &target );
	void	whoAmI( void );
};
