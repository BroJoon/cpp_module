#include "Peon.hpp"

Peon::Peon() : Victim()
{

}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &peon) : Victim(peon)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon& Peon::operator=(const Peon &peon)
{
	Victim::operator=(peon);
	return *this;
}

void Peon::getPolymorphed() const
{
	std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, Peon &peon)
{
	return (stream << "I'm " << peon.getName() << " and I like otters!" << std::endl);
}
