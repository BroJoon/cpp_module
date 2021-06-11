#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent zombieEvent;
	zombieEvent.setZombieType("Level: 1");
	for (int i = 0; i < 5; i++)
	{
		Zombie *zombie;
		zombie = zombieEvent.randomChump();
		delete zombie;
	}
	return (0);
}