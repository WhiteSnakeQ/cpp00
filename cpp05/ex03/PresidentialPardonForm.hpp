#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		PresidentialPardonForm( void );
		virtual void	executeConcrete( void ) const;
	public:
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		virtual ~PresidentialPardonForm( void );

		PresidentialPardonForm&	operator=( const PresidentialPardonForm& other );
};