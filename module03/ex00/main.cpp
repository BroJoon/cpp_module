#include "FragTrap.hpp"

int main(void)
{
	srand(time(NULL));

	FragTrap fragTrap("Unit 1");

	fragTrap.rangedAttack("The king");
	fragTrap.meleeAttack("The Queen");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(10);
	fragTrap.takeDamage(50);
	fragTrap.beRepaired(100);
	fragTrap.takeDamage(50);
	fragTrap.beRepaired(100);
	fragTrap.takeDamage(15);
	fragTrap.beRepaired(15); 
	fragTrap.takeDamage(1000);
	
	FragTrap fragTrap2("Unit 2");
	fragTrap2.vaulthunter_dot_exe("Human");
	fragTrap2.vaulthunter_dot_exe("Sorcerer");
	fragTrap2.vaulthunter_dot_exe("Knight");
	fragTrap2.vaulthunter_dot_exe("Giant");
	fragTrap2.vaulthunter_dot_exe("Ant");
	return 0;

}