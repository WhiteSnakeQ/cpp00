#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _energy(10), _damage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destractor called" << std::endl; 
}

void	ClapTrap::attack( std::string const &target )
{
	if (_hp <= 0)
	{
		std::cout << "Already dead" << std::endl;
		return ;
	}
	if (_energy <= 0 )
	{
		std::cout << _name << " dont have enaf energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hp <= 0)
	{
		std::cout << "Already dead" << std::endl;
		return ;
	}
	if (_energy <= 0 )
	{
		std::cout << _name << " dont have enaf energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repeired him seld - " << amount << std::endl;
	_energy--;
	_hp += amount;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hp <= 0)
	{
		std::cout << "Already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " took " << amount << " point of damage!" << std::endl;
	_hp -= amount;
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " dead!" << std::endl;
	}
}