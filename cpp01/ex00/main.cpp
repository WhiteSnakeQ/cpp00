#include "Zombie.hpp"

void	rundomChump( std::string name );
Zombie	*newZombie( std::string name );

int	main(void)
{
	Zombie *zom;

	zom = newZombie("Charlie");
	rundomChump("Thifz");
	rundomChump("Clara");
	rundomChump("Carl");

	delete (zom);
	return (0);
}