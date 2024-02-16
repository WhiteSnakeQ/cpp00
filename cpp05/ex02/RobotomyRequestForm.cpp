#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm( void )
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm("RobotomyRequestForm", target, 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy )
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &copy )
{
	(void)copy;
	return (*this);
}

void	RobotomyRequestForm::executeConcrete( void ) const
{
	if (rand() % 2 == 1)
	{
		std::cout << "BZZZZZZZZZZZZzzzzzzz........\n" << "BBZZZBZZBZBZZzzbzzzzbzzzz/..\n";
		std::cout << getTarget() << " is robotomized!" << std::endl;
	}
	else
		std::cout << "something is wrong" << std::endl;
}
