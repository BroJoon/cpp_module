#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	SuperMutant(const SuperMutant &superMutant);
	virtual ~SuperMutant();
	SuperMutant &operator=(const SuperMutant &superMutant);
	virtual void takeDamage(int);
};

#endif