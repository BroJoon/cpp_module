#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <string>
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap();
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap &superTrap);
	~SuperTrap();
	SuperTrap& operator=(const SuperTrap &superTrap);
};

#endif
