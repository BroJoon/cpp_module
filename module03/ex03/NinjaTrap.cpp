#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap() : ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, "name", "NINJ4-TP")
{
	std::cout << "NINJ4-TP <" << getName() << "> Created!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) :  ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, name, "NINJ4-TP")
{
	std::cout << "NINJ4-TP <" << getName() << "> Created!" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& ninjaTrap)
{
	*this = ninjaTrap;
	std::cout << "NINJ4-TP <" << getName() << "> Copied!" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NINJ4-TP <" << getName() << "> Destroyed!" << std::endl;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& ninjaTrap)
{
	ClapTrap::operator=(ninjaTrap);
	std::cout << "NINJ4-TP <" << getName() << "> Assigned!" << std::endl;
	return *this;
}

void NinjaTrap::ninjaShoebox(FragTrap &fragTrap)
{
	std::cout << "NINJ4-TP <" << getName() << "> Used Special Attack to " << "FR4G-TP <" << fragTrap.getName() << ">" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &scavTrap)
{
	std::cout << "NINJ4-TP <" << getName() << "> Used Special Attack to " << "SC4V-TP <" << scavTrap.getName() << ">" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &clapTrap)
{
	std::cout << "NINJ4-TP <" << getName() << "> Used Special Attack to " << "CL4P-TP <" << clapTrap.getName() << ">" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &ninjaTrap)
{
	std::cout << "NINJ4-TP <" << getName() << "> Used Special Attack to " << "NINJ4-TP <" << ninjaTrap.getName() << ">" << std::endl;
}