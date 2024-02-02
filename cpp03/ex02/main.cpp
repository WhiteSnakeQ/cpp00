/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:53 by kreys             #+#    #+#             */
/*   Updated: 2024/02/01 17:51:27 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	hero("Gery");

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
	hero.give_five();
	return (0);
}
