#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( Brain *copy )
{
	std::cout << "Brain copy constructor called" << std::endl;
	copy->getIdeas(*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::getIdeas( Brain &Brain )
{
	for (size_t i = 0; i < 100; i++)
		Brain._ideas[i] =_ideas[i];
}