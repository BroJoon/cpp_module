#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{

}

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &sorcerer)
{
	name = sorcerer.name;
	title = sorcerer.title;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer& Sorcerer::operator=(const Sorcerer &sorcerer)
{
	name = sorcerer.name;
	title = sorcerer.title;
	return *this;
}

std::string Sorcerer::getName() const
{
	return name;
}

std::string Sorcerer::getTitle() const 
{
	return title;
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream& operator<<(std::ostream &stream, Sorcerer &sorcerer)
{
	return (stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() <<
		", and I like ponies!" << std::endl);
}