#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		ShrubberyCreationForm( void );
		virtual void	executeConcrete( void ) const;
	public:
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		virtual ~ShrubberyCreationForm( void );

		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other );
};