#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade (1)
{

}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(1)
{
	setGrade(grade);
}

Bureaucrat::~Bureaucrat( void )
{

}

void	Bureaucrat::setGrade( int grade )
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

void	Bureaucrat::decrementGrade( int grade )
{
	if ( grade < 1 )
		return ;
	setGrade(getGrade() + grade);
}

void	Bureaucrat::incrementGrade( int grade )
{
	if ( grade < 1 )
		return ;
	setGrade(getGrade() - grade);
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low!");
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high!");
}

int	Bureaucrat::getGrade( void ) const { return (_grade); }
std::string Bureaucrat::getName( void ) const { return (_name); }

Bureaucrat	&Bureaucrat::operator=( Bureaucrat &bur )
{
	if (this == &bur)
		return (*this);
	_grade = bur.getGrade();
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &b )
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade(); 
	return (o);
}
