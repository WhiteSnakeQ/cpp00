#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		return (std::cout <<"Error: Wrong number of argument!" << std::endl, 0);
	harl.complain(argv[1]);
	return (0);
}
