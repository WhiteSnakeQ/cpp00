#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("NoName")
{
}

Zombie::Zombie( std::string name ) : _name(name)
{
}

Zombie::~Zombie()
{
	static int i = 0;

	if (i % 2 == 1)
		std::cout << _name  << ": was killed" << std::endl;
	else
		std::cout << _name  << ": go sleep..." << std::endl;
	i++;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
