#include "RobotomyRequestForm.hpp"
#include <fstream>
#include "cstdlib"

RobotomyRequestForm::RobotomyRequestForm( void )
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm("RobotomyRequestForm", target, 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) : AForm("RobotomyRequestForm", copy.getTarget(), copy.getSignGrade(), copy.getExecGrade())
{
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
