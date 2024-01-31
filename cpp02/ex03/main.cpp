#include "Fixed.hpp"
#include "Point.hpp"

std::string bool_str(bool i)
{
	if (i)
		return ("True");
	return ("False");
}

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(7, 8);
	Point	b(0, 0);
	Point	c(-5, 7);
	Point	test1(0, 0);
	Point	test2(5, 5);
	Point	test3(-1, 5);

	std::cout << "Triangle > " << a << " " << b << " " << c << std::endl;
	std::cout << test1 << " insize? - " << (bool_str(bsp(a, b, c, test1))) << std::endl;
	std::cout << test2 << " insize? - " << (bool_str(bsp(a, b, c, test2))) << std::endl;
	std::cout << test3 << " insize? - " << (bool_str(bsp(a, b, c, test3))) << std::endl;
	return (0);
}
