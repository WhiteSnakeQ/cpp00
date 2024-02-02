/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:49 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 17:51:35 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
private:
	int	_is_on_guard;
public:
	FragTrap( void );
	FragTrap( std::string name );
	~FragTrap();
	void	attack( std::string const &target );
	void	give_five( void );
};
