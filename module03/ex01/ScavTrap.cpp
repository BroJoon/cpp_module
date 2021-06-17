#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>

ScavTrap::ScavTrap()
{
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	level = 1;
	name = "name";
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;

	std::cout << "SC4V-TP <" << name << "> Created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	level = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;
	this->name = name;

	std::cout << "SC4V-TP <" << name << "> Created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
	*this = scavTrap;

	std::cout << "SC4V-TP <" << name << "> Copied!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP <" << name << "> Destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	hitPoints = scavTrap.hitPoints;
	maxHitPoints = scavTrap.maxHitPoints;
	energyPoints = scavTrap.energyPoints;
	maxEnergyPoints = scavTrap.maxEnergyPoints;
	level = scavTrap.level;
	meleeAttackDamage = scavTrap.meleeAttackDamage;
	rangedAttackDamage = scavTrap.rangedAttackDamage;
	armorDamageReduction = scavTrap.armorDamageReduction;
	name = scavTrap.name;
	
	std::cout << "SC4V-TP <" << name << "> Assigned!" << std::endl;
	return *this;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP <" << name << "> attacks <" << target << "> at range, causing <"
		<< rangedAttackDamage << "> points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP <" << name << "> attacks <" << target << "> at melee, causing <"
		<< meleeAttackDamage << "> points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	long long damage = amount - armorDamageReduction;
	damage = damage < hitPoints ? damage : hitPoints;
	damage = damage < 0 ? 0 : damage;
	std::cout << "SC4V-TP <" << name << "> take <"
		<< damage << "> points of damage!" << std::endl;
	hitPoints -= damage;
	if (hitPoints == 0)
		std::cout << "SC4V-TP <" << name << "> died!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	long long heal = amount;
	heal = hitPoints + heal > maxHitPoints ? maxHitPoints - hitPoints : heal;
	if (energyPoints < heal)
	{
		std::cout << "SC4V-TP <" << name << "> can't repaired" << std::endl;
		return;
	}
	energyPoints -= heal;
	hitPoints += heal;
	std::cout << "SC4V-TP <" << name << "> repaired by <" << heal << ">" << std::endl;
}

void ScavTrap::challengeNewcomer()
{
	std::string challenges[5] = {
		"Good as new, I think. Am I leaking?",
		"Turning off the optics... they can't see me...",
		"The traveler will protect me. The traveler will protect me.",
		"I'm detecting a motor unit malfunction... I can't move! I'm paralyzed with fear!",
		"My servos... are seizing..."
	};
	std::cout << "SC4V-TP <" << name << "> challenged " << challenges[rand() % 5] << std::endl;
}