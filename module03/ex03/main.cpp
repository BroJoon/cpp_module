#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	srand(time(NULL));

	FragTrap fragTrap("hyungjki1");

	fragTrap.rangedAttack("Enyme1");
	fragTrap.meleeAttack("Enyme2");
	fragTrap.takeDamage(30);
	fragTrap.beRepaired(10);
	fragTrap.beRepaired(100);
	fragTrap.takeDamage(90);
	fragTrap.beRepaired(100);
	fragTrap.vaulthunter_dot_exe("Enyme1");
	fragTrap.vaulthunter_dot_exe("Enyme1");
	fragTrap.vaulthunter_dot_exe("Enyme2");
	fragTrap.vaulthunter_dot_exe("Enyme1");
	fragTrap.vaulthunter_dot_exe("Enyme2");
	fragTrap.takeDamage(1000);

	std::cout << std::endl;

	ScavTrap scavTrap("hyungjki2");
	scavTrap.rangedAttack("Enyme3");
	scavTrap.meleeAttack("Enyme3");
	scavTrap.takeDamage(20);
	scavTrap.beRepaired(100);
	scavTrap.takeDamage(40);
	scavTrap.challengeNewcomer();
	scavTrap.challengeNewcomer();
	scavTrap.challengeNewcomer();
	scavTrap.challengeNewcomer();
	scavTrap.challengeNewcomer();
	scavTrap.takeDamage(1000);

	std::cout << std::endl;
	NinjaTrap ninja("hyungjki3");
	ninja.rangedAttack("Enyme4");
	ninja.meleeAttack("Enyme5");
	ninja.takeDamage(50);
	ninja.beRepaired(10);
	ninja.beRepaired(100);
	ninja.takeDamage(1000);

	std::cout << std::endl;

	NinjaTrap ninja2("ninja2");
	NinjaTrap ninja3("ninja3");
	ScavTrap scavTrap2("scar2");
	ClapTrap clapTrap("clap");
	FragTrap fragTrap2("frag2");
	ninja2.ninjaShoebox(scavTrap2);
	ninja2.ninjaShoebox(fragTrap2);
	ninja2.ninjaShoebox(ninja3);
	ninja2.ninjaShoebox(clapTrap);
	return 0;
}
