#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void )
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm("ShrubberyCreationForm", target, 125, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) : AForm("ShrubberyCreationForm", copy.getTarget(), copy.getSignGrade(), copy.getExecGrade())
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &copy )
{
	(void)copy;
	return (*this);
}

void	ShrubberyCreationForm::executeConcrete( void ) const
{
	std::fstream	file;

	file.open((getTarget() + "_shrubbery").c_str(), std::fstream::out | std::fstream::trunc);
	if (!file.is_open())
		std::cerr << "Error while opening Shrubbery target file" << std::endl;
	
	file << 
	"                    *             \n"
	"                   * *            \n"
	"                  * * *           \n"
	"                 * * * *          \n"
	"                * * * * *         \n"
	"               * * * * * *        \n"
	"              * * * * * * *       \n"
	"                   * *            \n"
	"                   * *            \n"
	"//////////////////////////////////\n";
	file.close();
}
