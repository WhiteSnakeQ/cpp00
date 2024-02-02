/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:49 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 15:30:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	int	_is_on_guard;
public:
	ScavTrap( std::string name );
	~ScavTrap();
	void	guardGate();
	void	attack( std::string const &target );
};
