#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	hero("Gery");

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