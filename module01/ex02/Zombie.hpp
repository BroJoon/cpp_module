#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string type;
		std::string name;
	public:
		Zombie();
		Zombie(std::string type, std::string name);
		~Zombie();
		void announce();
};

#endif