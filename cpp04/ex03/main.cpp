#include "MaterialSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void	test1( void )
{
	std::cout << "--------------  test1  --------------" << std::endl;

	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete(bob);
	delete(me);
	delete(src);
}

void	test2( void )
{
	std::cout << "\n\n--------------  test2  --------------" << std::endl;

	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*hero = new Character("Iva");
	ICharacter	*hero2 = new Character("Rouse");
	
	AMateria	*ice = new Ice();
	hero->equip(src->createMateria("ice"));
	hero->equip(src->createMateria("cure"));
	hero->equip(ice);

	hero->unequip(2);

	hero->use(0, *hero2);
	hero->use(1, *hero2);
	hero->use(2, *hero2);

	delete(src);
	delete(hero);
	delete(hero2);
	delete(ice);
}

void	test3( void )
{
	std::cout << "\n\n--------------  test3  --------------" << std::endl;

	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria	*ice = new Ice();
	src->learnMateria(ice);

	ICharacter	*hero = new Character("Iva");
	ICharacter	*hero2 = new Character("Rouse");
	
	hero->equip(src->createMateria("sdw"));
	hero->equip(src->createMateria("ice"));
	hero->equip(src->createMateria("cure"));
	hero->equip(src->createMateria("cure"));
	hero->equip(src->createMateria("cure"));
	hero->equip(ice);

	hero->use(0, *hero2);
	hero->use(1, *hero2);
	hero->use(2, *hero2);
	hero->use(3, *hero2);
	hero->use(4, *hero2);

	delete(src);
	delete(hero);
	delete(hero2);
	delete(ice);
}

int	main(void)
{
	test1();
	test2();
	test3();
	return (0);
}
