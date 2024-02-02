#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_damage  = FragTrap::_damage;
}

DiamondTrap::~DiamondTrap()
{
}

void	DiamondTrap::attack( std::string const &target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	if (_hp <= 0)
	{
		std::cout << _name << " Already dead" << std::endl;
		return ;
	}
	if (_energy <= 0 )
	{
		std::cout << _name << " dont have enaf energy!" << std::endl;
		return ;
	}
	std::cout << "My_name_is - " << name << "\nMy_second_name_is " << _name << std::endl;
}

