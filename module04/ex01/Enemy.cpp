#include "Enemy.hpp"

Enemy::Enemy()
{
	hp = 0;
	type = "";
}

Enemy::Enemy(const Enemy &enemy)
{
	hp = enemy.hp;
	type = enemy.type;
}

Enemy::Enemy(unsigned int hp, std::string const &type)
{
	this->hp = hp;
	this->type = type;
}

Enemy::~Enemy()
{
	return;
}

Enemy &Enemy::operator=(const Enemy &enemy)
{
	hp = enemy.hp;
	type = enemy.type;
	return *this;
}

std::string const &Enemy::getType() const
{
	return type;
}

int Enemy::getHP() const
{
	return hp;
}

void Enemy::takeDamage(int amount)
{
	if (amount > 0)
		if ((hp -= amount) < 0)
			hp = 0;
}