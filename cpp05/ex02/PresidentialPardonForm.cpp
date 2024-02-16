#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm( void )
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm("RobotomyRequestForm", target, 72, 45)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy )
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &copy )
{
	(void)copy;
	return (*this);
}

void	PresidentialPardonForm::executeConcrete( void ) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox";
}
