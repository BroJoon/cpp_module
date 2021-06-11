#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	name = "default";
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;

	std::cout << "FR4G-TP" << name << "> Created!" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	this->name = name;

	std::cout << "FR4G-TP <" << name << "> Created!" << std::endl;
}