#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include <iostream>

int main()
{
	Character *me = new Character("me");

	std::cout << *me;

	Enemy *b = new RadScorpion();
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << "==== TEST ====" << std::endl << std::endl;
	Enemy *enemy = new SuperMutant();
	for(int i = 0;i < 11; i++)
		me->attack(enemy);
	std::cout << *me;
	std::cout << enemy->getHP() << std::endl;
	for(int i = 0;i < 8; i++)
	{
		me->recoverAP();
		std::cout << *me;
	}
	for(int i = 0;i < 5; i++)
	{
		me->attack(enemy);
		std::cout << enemy->getHP() << std::endl;
	}
	me->attack(enemy);

	delete pr;
	delete pf;
	delete me;

	return (0);
}