#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &superMutant) : Enemy(superMutant)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant &SuperMutant::operator=(const SuperMutant &superMutant)
{
	Enemy::operator=(superMutant);
	return *this;
}

void SuperMutant::takeDamage(int amount)
{
	Enemy::takeDamage(amount - 3);
}