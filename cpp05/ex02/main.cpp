#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat	crat("Oleg", 44);
		AForm		*f = new RobotomyRequestForm("Grizle");
		crat.signForm(*f);
		crat.executeForm(*f);
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	

	return (0);
}