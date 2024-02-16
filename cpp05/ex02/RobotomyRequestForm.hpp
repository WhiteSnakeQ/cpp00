#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		RobotomyRequestForm( void );
		virtual void	executeConcrete( void ) const;
	public:
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		virtual ~RobotomyRequestForm( void );

		RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
};