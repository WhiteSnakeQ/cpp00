/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:51 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 17:51:42 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	_is_on_guard = 0;
	std::cout << "FragTrap DeffConstructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name, 100, 100, 30)
{
	_is_on_guard = 0;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destractor called" << std::endl;
}

void	FragTrap::attack( std::string const &target )
{
	if (_hp <= 0)
	{
		std::cout << "FragTrap Already dead" << std::endl;
		return ;
	}
	if (_energy <= 0 )
	{
		std::cout << _name << " dont have enaf energy!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	FragTrap::give_five( void )
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
	std::cout << "Give Five!" << std::endl;
	_energy--;
}
