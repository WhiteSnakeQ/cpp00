#include "iostream"

int	main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << &str << " -- Memory addres string" << std::endl;
	std::cout << strPTR << " -- Memory addres pointer" << std::endl;
	std::cout << &strREF << " -- Memory addres reference" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << str << " -- value string" << std::endl;
	std::cout << *strPTR << " -- value addres pointer" << std::endl;
	std::cout << strREF << " -- value addres reference" << std::endl;
}
