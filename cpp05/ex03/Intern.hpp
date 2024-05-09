#pragma once
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &intern);
		~Intern();

		Intern	&operator=(const Intern &intern);

		AForm	*makeForm(const std::string formName, const std::string target) const;
};

typedef AForm *(*constructorPtr)(const std::string);
