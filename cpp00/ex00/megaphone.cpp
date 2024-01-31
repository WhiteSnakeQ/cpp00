#include <iostream>
#include <string>
#include <algorithm>

int	main(int argc, char **argv)
{
	std::string	str;

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NISE *";
	std::cout << std::endl;
}
