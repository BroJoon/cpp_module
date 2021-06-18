#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
private:
	int count;
	int size;
	ISpaceMarine** array;
public:
	Squad();
	Squad(const Squad& squad);
	virtual ~Squad();

	Squad &operator=(const Squad& squad);

	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int) const;
	virtual int push(ISpaceMarine*);
};

#endif