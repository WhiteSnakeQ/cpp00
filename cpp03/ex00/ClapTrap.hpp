/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:45:10 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 11:45:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
