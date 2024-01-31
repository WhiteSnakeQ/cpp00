#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name );

int	main(void)
{
	Zombie *zombies;
	int		num_zombie = 6;

	zombies = zombieHorde(num_zombie, "Stive");
	for (int i = 0; i < num_zombie; i++)
		zombies[i].announce();
	delete[] (zombies);
	return (0);
}