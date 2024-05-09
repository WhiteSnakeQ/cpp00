#include "whatever.hpp"

int	main(void)
{
	{
	int	a;
	int	b;

	std::string	aa;
	std::string	bb;

	a = 1;
	b = 2;
	aa = "first";
	bb = "second";

	std::cout << "a - " << a << std::endl;
	std::cout << "b - " << b << std::endl;
	std::cout << "aa - " << aa << std::endl;
	std::cout << "bb - " << bb << std::endl;
	swap(a, b);
	std::cout << "swap a b"<< std::endl;
	std::cout << "a - " << a << std::endl;
	std::cout << "b - " << b << std::endl;
	std::cout << "min a b"<< std::endl;
	std::cout << "result - " << min(a, b) << std::endl;
	std::cout << "max a b"<< std::endl;
	std::cout << "result - " << max(a, b) << std::endl;
	std::cout << "swap aa bb"<< std::endl;
	swap(aa, bb);
	std::cout << "aa - " << aa << std::endl;
	std::cout << "bb - " << bb << std::endl;
	std::cout << "\n\n" << std::endl;
	}
	{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return (0);
}