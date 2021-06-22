#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

FragTrap::FragTrap()
{
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	name = "name";
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;

	std::cout << "FR4G-TP <" << name << "> Created!" << std::endl;
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

FragTrap::FragTrap(const FragTrap& fragTrap)
{
	*this = fragTrap;

	std::cout << "FR4G-TP <" << name << "> Copied!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP <" << name << "> Destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	hitPoints = fragTrap.hitPoints;
	maxHitPoints = fragTrap.maxHitPoints;
	energyPoints = fragTrap.energyPoints;
	maxEnergyPoints = fragTrap.maxEnergyPoints;
	level = fragTrap.level;
	meleeAttackDamage = fragTrap.meleeAttackDamage;
	rangedAttackDamage = fragTrap.rangedAttackDamage;
	armorDamageReduction = fragTrap.armorDamageReduction;
	name = fragTrap.name;

	std::cout << "FR4G-TP <" << name << "> Assigned!" << std::endl;
	return *this;
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP <" << name << "> attacks <" << target << "> at range, causing <"
		<< rangedAttackDamage << "> points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP <" << name << "> attacks <" << target << "> at melee, causing <"
		<< meleeAttackDamage << "> points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	long long damage = amount - armorDamageReduction;
	damage = damage < hitPoints ? damage : hitPoints;
	damage = damage < 0 ? 0 : damage;
	std::cout << "FR4G-TP <" << name << "> take <"
		<< damage << "> points of damage!" << std::endl;
	hitPoints -= damage;
	if (hitPoints == 0)
		std::cout << "FR4G-TP <" << name << "> died!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	long long heal = amount;
	heal = hitPoints + heal > maxHitPoints ? maxHitPoints - hitPoints : heal;
	hitPoints += heal;
	std::cout << "FR4G-TP <" << name << "> repaired by <" << heal << ">" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::string attacks[5] = {
		"I am ornado of death and bullets!",
		"Stop me before I kill again, except don't!",
		"Ha ha ha! Fall before your robot overlord!",
		"Can't touch this!",
		"Ha! Keep 'em coming!"
	};

	unsigned int damage[] = {1, 2, 4, 8, 16};
	int random = rand() % 5;
	if (energyPoints >= 25)
	{
		energyPoints -= 25;
		std::cout << "FR4G-TP <" << name << "> attacks <" << target 
		<< "> with " << attacks[random] << ", causing <"
		<< damage[random] << "> points of damage!" << std::endl;
		return;
	}
	std::cout << "FR4G-TP <" << name << "> Hnngh! Empty!" << std::endl;
}
