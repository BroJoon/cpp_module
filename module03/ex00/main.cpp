#include <cstdlib>
#include <iostream>
#include "FragTrap.hpp"

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

	return 0;
}
