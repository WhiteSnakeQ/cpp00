#pragma once

#include "iostream"

class	Bureaucrat;

class	AForm
{
protected:
	virtual void	executeConcrete( void ) const = 0;
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_toSign;
	const int			_toExecute;
	std::string			_target;
public:
	AForm( void );
	AForm( std::string name, int toSign, int toExecute );
	AForm( std::string name, std::string target, int toSign, int toExecute );
	~AForm( void );

	void			beSigned( Bureaucrat const &bur );
	void			execute( Bureaucrat const &executor ) const;

	AForm	&operator=( AForm const &bur );

	std::string	getName( void ) const;
	std::string	getTarget( void ) const;
	bool		isSigned( void ) const;
	int			getSignGrade( void ) const;
	int			getExecGrade( void ) const;

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotSigned : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &o, AForm const &f );
