#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "==== MY TEST ====" << std::endl << std::endl;
	
	me->use(3, *bob);

	Ice *ice = new Ice();
	Ice *ice2 = new Ice();
	me->equip(ice);
	me->equip(ice2);
	me->use(2, *bob);
	me->use(2, *bob);
	me->use(2, *bob);
	me->use(2, *bob);
	std::cout << "ice xp: " << ice->getXP() << std::endl;
	std::cout << "ice2 xp: " << ice2->getXP() << std::endl;
	*ice2 = *ice;
	std::cout << "ice2 xp: " << ice2->getXP() << std::endl;

	std::cout << src->createMateria("fire") << std::endl;

	me->unequip(2);
	me->unequip(3);
	me->use(2, *bob);

	Character *me2 = new Character("me2");
	Character *me3 = new Character("me3");
	me3->equip(ice);
	me3->equip(ice2);
	me3->use(1, *bob);
	*me2 = *me3;
	std::cout << "=== me2 ice bolt ===" << std::endl;
	me2->use(0, *bob);
	me2->use(1, *bob);
	me2->use(2, *bob);

	delete me;
	delete me2;
	delete me3;
	delete bob;
	delete src;

	return (0);
}