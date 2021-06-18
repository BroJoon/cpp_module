#include "Cat.hpp"

Cat::Cat() : Victim()
{

}

Cat::Cat(std::string name) : Victim(name)
{
	std::cout << "Meow meow." << std::endl;
}

Cat::Cat(const Cat &cat) : Victim(cat)
{
	std::cout << "Meow meow." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Hiss..." << std::endl;
}

Cat& Cat::operator=(const Cat &cat)
{
	Victim::operator=(cat);
	return *this;
}

void Cat::getPolymorphed() const
{
	std::cout << getName() << " has been turned into a scary lion!" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, Cat &cat)
{
	return (stream << "I'm " << cat.getName() << " and I like otters!" << std::endl);
}