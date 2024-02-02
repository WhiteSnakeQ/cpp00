/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:51 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 15:30:22 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	_is_on_guard = 0;
	std::cout << "ScavTrap DeffConstructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20)
{
	_is_on_guard = 0;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destractor called" << std::endl;
}

void	ScavTrap::attack( std::string const &target )
{
	if (_hp <= 0)
	{
		std::cout << "ScavTrap Already dead" << std::endl;
		return ;
	}
	if (_energy <= 0 )
	{
		std::cout << _name << " dont have enaf energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	ScavTrap::guardGate( void )
{
	if (_hp <= 0)
	{
		std::cout << "ScavTrap Already dead" << std::endl;
		return ;
	}
	if (_is_on_guard == 1)
	{
		std::cout << "ScavTrap " << _name << " already on guard" << std::endl;
		return ;
	}
	_is_on_guard = 1;
	std::cout << "ScavTrap " << _name << " stay on guard" << std::endl;
}
