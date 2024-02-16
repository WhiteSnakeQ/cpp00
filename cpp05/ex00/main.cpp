#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		const Bureaucrat	b("Oleg", 27);

		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		const Bureaucrat	b("Oset", 151);

		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		const Bureaucrat	b("Sofa", 0);

		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	b("Lodur", 1);

		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
