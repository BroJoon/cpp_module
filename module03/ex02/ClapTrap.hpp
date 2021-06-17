#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
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
	std::string type;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints, unsigned int energyPoints,
		unsigned int maxEnergyPoints, unsigned int level, unsigned int meleeAttackDamage,
		unsigned int rangedAttackDamage, unsigned int armorDamageReduction, std::string name,
		std::string type);
	ClapTrap(const ClapTrap& clapTrap);
	virtual ~ClapTrap();
	ClapTrap& operator=(const ClapTrap& clapTrap);

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string &getName();
	unsigned int &getEnergyPoint();
};

#endif
