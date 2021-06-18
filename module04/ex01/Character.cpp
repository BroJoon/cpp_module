#include "Character.hpp"

Character::Character()
{
	name = "";
	ap = 40;
	weapon = NULL;
}

Character::Character(std::string const &name)
{
	this->name = name;
	ap = 40;
	weapon = NULL;
}

Character::Character(const Character &character)
{
	name = character.name;
	ap = character.ap;
	weapon = character.weapon;
}

Character::~Character()
{

}

Character &Character::operator=(const Character &character)
{
	name = character.name;
	ap = character.ap;
	weapon = character.weapon;
	return *this;
}

void Character::recoverAP()
{
	if ((ap += 10) > 40)
		ap = 40;
}

void Character::equip(AWeapon* weapon)
{
	this->weapon = weapon;
}

void Character::attack(Enemy* enemy)
{
	if (weapon && enemy)
	{
		int after = ap - weapon->getAPCost();
		if (after < 0)
			return;
		std::cout << name << " attacks " << enemy->getType() << " with a " << weapon->getName() << std::endl;
		weapon->attack();
		enemy->takeDamage(weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
		ap = after;
	}
}

std::string const &Character::getName() const
{
	return name;
}

int Character::getAP()
{
	return ap;
}

AWeapon const *Character::getWeapon() const
{
	return weapon;
}

std::ostream& operator<<(std::ostream &stream, Character &character)
{
	if (character.getWeapon())
		return (stream << character.getName() << " has " << character.getAP() 
			<< " AP and wields a " << character.getWeapon()->getName() << std::endl);
	else
		return (stream << character.getName() << " has " << character.getAP() 
			<< " AP and is unarmed" << std::endl);
}
