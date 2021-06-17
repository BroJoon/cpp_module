#include "SuperTrap.hpp"
#include <iostream>
#include <cstdlib>

SuperTrap::SuperTrap() : ClapTrap(100, 100, 120, 120, 1, 60, 20, 5, "name", "SUPER-TP"), FragTrap(), NinjaTrap()
{
	std::cout << "SUPER-TP <" << FragTrap::getName() << "> Created!" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(100, 100, 120, 120, 1, 60, 20, 5, name, "SUPER-TP"), FragTrap(), NinjaTrap()
{
	std::cout << "SUPER-TP <" << FragTrap::getName() << "> Created!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& superTrap)
{
	*this = superTrap;

	std::cout << "SUPER-TP <" << FragTrap::getName() << "> Copied!" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUPER-TP <" << FragTrap::getName() << "> Destroyed!" << std::endl;
}

SuperTrap& SuperTrap::operator=(const SuperTrap& superTrap)
{
	ClapTrap::operator=(superTrap);
	std::cout << "SUPER-TP <" << FragTrap::getName() << "> Assigned!" << std::endl;
	return *this;
}