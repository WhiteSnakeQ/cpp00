#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : _name("Deff"), _isSigned(false), _toSign(1), _toExecute(1)
{

}

AForm::AForm( std::string name, int toSign, int toExecute ) : _name(name), _isSigned(false), _toSign(toSign), _toExecute(toExecute)
{
	if (_toSign > MIN_GRADE || _toExecute > MIN_GRADE)
		throw GradeTooLowException();
	else if (_toSign < MAX_GRADE || _toExecute < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::~AForm( void )
{

}

void	AForm::beSigned( Bureaucrat const &bur )
{
	if (bur.getGrade() <= _toSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low!");
}

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high!");
}

std::string	AForm::getName( void ) const { return (_name); }
bool	AForm::isSigned( void ) const { return (_isSigned); }
int	AForm::getSignGrade( void ) const { return (_toSign); }
int	AForm::getExecGrade( void ) const { return (_toExecute); }

AForm	&AForm::operator=( const AForm &f )
{
	(void)f;
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, AForm const &f )
{
	o << f.getName() << "\nIs it signed?";
	if (f.isSigned())
		o << "Yes\n";
	else
		o << "No\n";
	o << "Grade to sine - " << f.getSignGrade() << "\n";
	o << "Grade to execute - " << f.getExecGrade();
	return (o);
}