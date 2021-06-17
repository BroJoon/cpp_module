#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>

ScavTrap::ScavTrap() : ClapTrap(100, 100, 50, 50, 1, 20, 15, 3, "name", "SC4V-TP")
{
	std::cout << "SC4V-TP <" << getName() << "> Created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 100, 50, 50, 1, 20, 15, 3, name, "SC4V-TP")
{
	std::cout << "SC4V-TP <" << getName() << "> Created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
	*this = scavTrap;

	std::cout << "SC4V-TP <" << getName() << "> Copied!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP <" << getName() << "> Destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	ClapTrap::operator=(scavTrap);
	std::cout << "SC4V-TP <" << getName() << "> Assigned!" << std::endl;
	return *this;
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
	std::cout << "SC4V-TP <" << getName() << "> challenged " << challenges[rand() % 5] << std::endl;
}