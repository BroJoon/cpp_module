#include "ZombieEvent.hpp"

std::string random_string()
{
	std::string eng("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::string result("");

	for (int i = 0; i < 10; i++)
		result += eng[rand() % eng.length()];
	return result;
}

ZombieEvent::ZombieEvent()
{
	type = "default_type";
	srand(time(NULL));
}

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	return new Zombie(type, name);
}

Zombie* ZombieEvent::randomChump()
{
	Zombie *zombie = newZombie(random_string());
	zombie->announce();
	return (zombie);
}