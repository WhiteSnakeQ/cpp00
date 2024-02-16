#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		const Bureaucrat	b("Oleg", 5);
		AForm				f("f1", 10, 5);
	
		b.signForm(f);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		const Bureaucrat	b("Cate", 24);
		AForm				f("f1", 10, 5);
	
		b.signForm(f);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}