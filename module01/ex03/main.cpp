#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde* horde = new ZombieHorde(4);
	horde->announce();
	delete horde;
	return (0);
}