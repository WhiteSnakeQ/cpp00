/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:55 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 15:31:33 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name, unsigned int hp, unsigned int energy, unsigned int damage ) : _name(name), _hp(hp), _energy(energy), _damage(damage)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destractor called" << std::endl; 
}

void	ClapTrap::attack( std::string const &target )
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
	std::cout << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	ClapTrap::beRepaired( unsigned int amount )
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
	std::cout << _name << " repeired him seld - " << amount << std::endl;
	_energy--;
	_hp += amount;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hp <= 0)
	{
		std::cout << _name << " Already dead" << std::endl;
		return ;
	}
	std::cout << _name << " took " << amount << " point of damage!" << std::endl;
	_hp -= amount;
	if (_hp <= 0)
	{
		std::cout << _name << " dead!" << std::endl;
	}
}
