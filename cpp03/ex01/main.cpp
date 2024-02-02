/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:53 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 17:51:03 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	hero("Gery");
	ScavTrap	hero2("Jec");
	
	hero2.attack("someOne");
	hero2.beRepaired(5);
	hero2.beRepaired(6);
	hero2.beRepaired(8);
	hero2.beRepaired(12);
	hero2.beRepaired(1);
	hero2.beRepaired(12);
	hero2.attack("asd");
	hero2.attack("Dragon!");
	hero2.attack("Elfs!");
	hero2.beRepaired(5);
	hero2.takeDamage(100);
	hero2.attack("s");
	hero2.beRepaired(76);
	hero2.takeDamage(7);
	hero2.guardGate();
	hero2.guardGate();
	std::cout << std::endl;
	hero.attack("someOne");
	hero.beRepaired(5);
	hero.beRepaired(6);
	hero.beRepaired(8);
	hero.beRepaired(12);
	hero.beRepaired(1);
	hero.beRepaired(12);
	hero.attack("asd");
	hero.attack("Dragon!");
	hero.attack("Elfs!");
	hero.beRepaired(5);
	hero.takeDamage(100);
	hero.attack("s");
	hero.beRepaired(76);
	hero.takeDamage(7);
	return (0);
}
