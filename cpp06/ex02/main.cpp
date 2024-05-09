#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
	int	val;

	std::cout << "Create class - ";
	val = std::rand();
	if (val % 3 == 0)
	{
		std::cout << "A" << std::endl;
		return (new A);
	}
	else if (val % 3 == 1)
	{
		std::cout << "B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "C" << std::endl;
		return (new C);
	}
}

void identify(Base* p)
{
	std::cout << "This is class ";
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "'A'!" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "'B'!" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "'C'!" << std::endl;
	else
		std::cout << "ERROR" << std::endl;
}

void identify(Base &p)
{
	std::cout << "This is class ";
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "'A'!" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "'B'!" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "'C'!" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "ERROR" << std::endl;
}


int	main(void)
{
	std::cout << "TEST 1 START" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		Base	*a;

		a = generate();
		identify(a);
		delete(a);
		std::cout << std::endl;
	}
	std::cout << "\n\nTEST 2 START" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		Base	*a;

		a = generate();
		identify(&(*a));
		delete(a);
		std::cout << std::endl;
	}
}