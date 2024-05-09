#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
	Intern	a;
	AForm	*b;

	b = a.makeForm("shrubbery creation", "olta");
	delete ((ShrubberyCreationForm *)b);
	}
	{
	Intern	a;
	AForm	*b;

	b = a.makeForm("Robotomy Request", "olta2");
	delete ((RobotomyRequestForm *)b);
	}
	{
	Intern	a;
	AForm	*b;

	b = a.makeForm("Presidential Pardon", "olta");
	delete ((PresidentialPardonForm *)b);
	}
	{
	Intern	a;
	a.makeForm("bdhd dfdf", "olta");
	}
	return (0);
}