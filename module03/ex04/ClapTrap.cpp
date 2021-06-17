#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>

ClapTrap::ClapTrap()
{
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	name = "name";
	type = "type";

	std::cout << "CL4P-TP <" << name << "> Created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
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
	this->type = "CL49-TP";

	std::cout << "CL4P-TP <" << name << "> Created!" << std::endl;
}

ClapTrap::ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints, unsigned int energyPoints,
		unsigned int maxEnergyPoints, unsigned int level, unsigned int meleeAttackDamage,
		unsigned int rangedAttackDamage, unsigned int armorDamageReduction, std::string name,
		std::string type)
{
	this->hitPoints = hitPoints;
	this->maxHitPoints = maxHitPoints;
	this->energyPoints = energyPoints;
	this->maxEnergyPoints = maxEnergyPoints;
	this->level = level;
	this->meleeAttackDamage = meleeAttackDamage;
	this->rangedAttackDamage = rangedAttackDamage;
	this->armorDamageReduction = armorDamageReduction;
	this->name = name;
	this->type = type;

	std::cout << "CL4P-TP <" << name << "> Created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	*this = clapTrap;

	std::cout << "CL4P-TP <" << name << "> Copied!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP <" << name << "> Destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	hitPoints = clapTrap.hitPoints;
	maxHitPoints = clapTrap.maxHitPoints;
	energyPoints = clapTrap.energyPoints;
	maxEnergyPoints = clapTrap.maxEnergyPoints;
	level = clapTrap.level;
	meleeAttackDamage = clapTrap.meleeAttackDamage;
	rangedAttackDamage = clapTrap.rangedAttackDamage;
	armorDamageReduction = clapTrap.armorDamageReduction;
	name = clapTrap.name;
	type = clapTrap.type;
	std::cout << "CL4P-TP <" << name << "> Assigned!" << std::endl;
	return *this;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << type << " <" << name << "> attacks <" << target << "> at range, causing <"
		<< rangedAttackDamage << "> points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << type << " <" << name << "> attacks <" << target << "> at melee, causing <"
		<< meleeAttackDamage << "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	long long damage = amount - armorDamageReduction;
	damage = damage < hitPoints ? damage : hitPoints;
	damage = damage < 0 ? 0 : damage;
	std::cout << type << " <" << name << "> take <"
		<< damage << "> points of damage!" << std::endl;
	hitPoints -= damage;
	if (hitPoints == 0)
		std::cout << type << " <" << name << "> died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	long long heal = amount;
	heal = hitPoints + heal > maxHitPoints ? maxHitPoints - hitPoints : heal;
	if (energyPoints < heal)
	{
		std::cout << type << " <" << name << "> can't repaired" << std::endl;
		return;
	}
	energyPoints -= heal;
	hitPoints += heal;
	std::cout << type << " <" << name << "> repaired by <" << heal << ">" << std::endl;
}

std::string &ClapTrap::getName()
{
	return name;
}

std::string &ClapTrap::getType()
{
	return type;
}

unsigned int &ClapTrap::getEnergyPoint()
{
	return energyPoints;
}