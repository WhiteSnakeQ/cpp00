#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void	Bureaucrat::signForm( AForm &f ) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << f.getName() << " because " << e.what() << "\n";
	}
	
}

void	Bureaucrat::setGrade( int grade )
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
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

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &bur )
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
