#include "MaterialSource.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "MaterialSoarce constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		_materials[i] = 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MaterialSoarce destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!_materials[i])
			return ;
		delete(_materials[i]);
	}
}

void	MateriaSource::learnMateria( AMateria *m )
{
	std::cout << "Lear new material" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (!_materials[i])
		{
			_materials[i] = m;
			return ;
		}
	}
	std::cout << "Lean failled!" << std::endl;
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	std::cout << "Create material " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!_materials[i])
		{
			std::cout << "Create material failed" << std::endl;
			return (NULL);
		}
		if (_materials[i]->getType() == type)
			return (_materials[i]->clone());
	}
	std::cout << "Create material failed" << std::endl;
	return (NULL);
}