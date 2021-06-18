#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"
#include <iostream>

class Peon : public Victim
{
protected:
	Peon();
public:
	Peon(std::string name);
	Peon(const Peon &peon);
	virtual ~Peon();
	Peon& operator=(const Peon &peon);

	virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &stream, Peon &peon);

#endif