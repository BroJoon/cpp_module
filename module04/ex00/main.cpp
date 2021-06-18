#include <iostream>
#include "Peon.hpp"
#include "Cat.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Cat bob("bob");
	std::cout << robert << jim << joe << bob;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(bob);
	return 0;
}