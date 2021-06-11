#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony* pony = new Pony("pony_heap");
	pony->print_name();
	std::cout << "Delete pony on the heap" << std::endl;
	delete pony;
}

void ponyOntheStack()
{
	Pony pony("pony_stack");
	pony.print_name();
	std::cout << "Delete pony on the stack" << std::endl;
}

int main()
{
	std::cout << "Pony heap" << std::endl;
	ponyOnTheHeap();
	std::cout << "Pony stack" << std::endl;
	ponyOntheStack();
	return (0);
}