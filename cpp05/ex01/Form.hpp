#pragma once

#include "iostream"

class	Bureaucrat;

class	AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_toSign;
	const int			_toExecute;
public:
	AForm( void );
	AForm( std::string name, int toSign, int toExecute );
	~AForm( void );

	void	beSigned( Bureaucrat const &bur );

	AForm	&operator=( AForm const &bur );

	std::string	getName( void ) const;
	bool		isSigned( void ) const;
	int			getSignGrade( void ) const;
	int			getExecGrade( void ) const;

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

std::ostream	&operator<<( std::ostream &o, AForm const &f );
