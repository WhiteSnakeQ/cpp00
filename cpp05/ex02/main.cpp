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
	
	try
	{
		Bureaucrat	crat2("Kat", 26);
		AForm		*f2 = new PresidentialPardonForm("Found");
		crat2.signForm(*f2);
		crat2.executeForm(*f2);
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	try
	{
		Bureaucrat	crat2("Sol", 87);
		AForm		*f2 = new ShrubberyCreationForm("Sectri");
		crat2.signForm(*f2);
		crat2.executeForm(*f2);
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	return (0);
}