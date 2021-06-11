#include "Zombie.hpp"

Zombie::Zombie()
{
	this->type = "default_type";
	this->name = "default_name";
}

Zombie::Zombie(std::string type, std::string name) : type(type), name(name)
{
	return;
}

Zombie::~Zombie()
{
	std::cout << "<" << name << " (" << this->type << ")> " << "gooooodddddbbbbye..." << std::endl;
}

void Zombie::announce()
{
	std::cout << "<" << name << " (" << this->type << ")> " << "Braiiiiiiinnnssss..." << std::endl;
}