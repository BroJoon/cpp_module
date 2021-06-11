#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <cstdlib>
#include <iostream>

class FragTrap
{
	private:
		unsigned int hitPoints;
		unsigned int maxHitPoints;
		unsigned int energyPoints;
		unsigned int maxEnergyPoints;
		unsigned int level;
		unsigned int meleeAttackDamage;
		unsigned int rangedAttackDamage;
		unsigned int armorDamageReduction;
		std::string name;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();
		FragTrap& operator=(const FragTrap& fragTrap);

		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const &target);

}


#endif