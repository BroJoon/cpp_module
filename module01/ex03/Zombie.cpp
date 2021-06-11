#include "Zombie.hpp"

Zombie::Zombie()
{
	this->type ="default_type";
	this->name = "default_name";
}

Zombie::Zombie(std::string type, std::string name)
{
	this->type = type;
	this->name = name;
}

Zombie::~Zombie()
{
std::cout << "<" << name << " (" << this->type << ")> " << "Goooooodbbbbbyeee..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::setType(std::string type)
{
	this->type = type;
}

void Zombie::announce()
{
	std::cout << "<" << name << " (" << this->type << ")> " << "Braiiiiiiinnnssss..." << std::endl;
}