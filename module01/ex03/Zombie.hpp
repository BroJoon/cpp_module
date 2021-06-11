#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string type;
		std::string name;
	public:
		Zombie();
		Zombie(std::string type, std::string name);
		~Zombie();
		void setName(std::string name);
		void setType(std::string type);
		void announce();
};

#endif