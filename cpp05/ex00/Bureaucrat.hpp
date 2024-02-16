#pragma once

#include "iostream"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
private:
	const std::string		_name;
	int						_grade;
public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	~Bureaucrat( void );
	void	setGrade( int grade );
	void	incrementGrade( int val = 1 );
	void	decrementGrade( int val = 1 );

	std::string	getName( void ) const;
	int			getGrade( void ) const;


	Bureaucrat	&operator=( Bureaucrat &bur );

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &b );
