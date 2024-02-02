/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:54 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 15:32:24 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class ClapTrap
{
protected:
	std::string _name;
	int			_hp;
	int			_energy;
	int			_damage;
public:
	ClapTrap( std::string name = "default" );
	ClapTrap( std::string name, unsigned int hp, unsigned int energy, unsigned int damage);
	~ClapTrap();
	virtual void	attack( std::string const &target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
};
