#include "iter.hpp"

template <typename T>
void	print(const T &i)
{
	std::cout << i << std::endl;
}

int	main(void)
{
	int	arr[] = {5, 5, 2, 1};
	std::string	arr2[] = {"hello", "killos", "StarCraft2"};

	::iter(arr, 4, &print);
	::iter(arr2, 3, &print);

	return (0);
}