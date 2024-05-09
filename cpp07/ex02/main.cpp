#include "Array.hpp"

int	main(void)
{
	Array<int>	digit(10);

	digit[9] = 25;
	std::cout << digit[11] << std::endl;
}