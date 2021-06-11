#include "ZombieHorde.hpp"

std::string random_string()
{
	std::string eng("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::string result("");

	for (int i = 0; i < 10; i++)
		result += eng[rand() % eng.length()];
	return result;
}

ZombieHorde::ZombieHorde(int n)
{
	srand(time(NULL));
	if (n < 1)
		n = 1;
	this->zombieNum = n;
	this->zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		zombies[i].setName(random_string());
		zombies[i].setType(random_string());
	}
}

void ZombieHorde::announce()
{
	for (int i = 0; i < zombieNum; i++)
	{
		zombies[i].announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] zombies;
}