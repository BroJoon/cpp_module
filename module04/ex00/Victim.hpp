#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{
private:
	std::string name;
protected:
	Victim();
public:
	Victim(std::string name);
	Victim(const Victim &victim);
	virtual ~Victim();
	Victim& operator=(const Victim &victim);

	const std::string &getName() const;
	virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &stream, Victim &victim);

#endif
