#include "Character.hpp"

Character::Character()
{
	for(int i = 0;i < 4;i++)
		array[i] = NULL;
	name = "";
}

Character::Character(std::string name)
{
	for(int i = 0;i < 4;i++)
		array[i] = NULL;
	this->name = name;
}

Character::Character(const Character& other)
{
	for(int i = 0;i < 4;i++)
		array[i] = NULL;
	operator=(other);
}

Character::~Character()
{
	for(int i = 0;i < 4;i++)
		if(array[i])
			delete array[i];
}

Character &Character::operator=(const Character& other)
{
	for(int i = 0;i < 4;i++)
		if(array[i])
			delete array[i];
	for(int i = 0;i < 4;i++)
		array[i] = other.array[i] ? other.array[i]->clone() : NULL;
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0;i < 4;i++)
	{
		if (!array[i])
		{
			array[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || 4 <= idx)
		return;
	array[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || 4 <= idx)
		return;
	if (array[idx])
		array[idx]->use(target);
}
