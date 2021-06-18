#include <iostream>
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
	// ISpaceMarine *bob = new TacticalMarine;
	// ISpaceMarine *jim = new AssaultTerminator;

	// ISquad *vlc = new Squad;

	// vlc->push(bob);
	// vlc->push(jim);

	// for (int i = 0; i < vlc->getCount(); ++i)
	// {
	// 	ISpaceMarine *cur = vlc->getUnit(i);
	// 	cur->battleCry();
	// 	cur->rangedAttack();
	// 	cur->meleeAttack();
	// }

	// delete vlc;

	std::cout << "==== MY TEST ====" << std::endl << std::endl;
	Squad *squad = new Squad();
	std::cout << squad->getCount() << std::endl;
	for (int i = 0;i < 30;i++)
		squad->push(new AssaultTerminator());
	std::cout << squad->getCount() << std::endl;

	Squad *squad2 = new Squad();
	std::cout << squad2->getCount() << std::endl;
	*squad2 = *squad;
	std::cout << squad2->getCount() << std::endl;
	squad2->push(new TacticalMarine());
	std::cout << squad2->getCount() << std::endl;
	*squad = *squad2;
	std::cout << squad->getCount() << std::endl;
	for (int i = 0;i < 35;i++)
	{
		if (squad->getUnit(i))
			squad->getUnit(i)->meleeAttack();
	}

	delete squad;
	delete squad2;

	return (0);
}