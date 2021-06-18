#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* array[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource&);
	virtual ~MateriaSource();

	MateriaSource &operator=(const MateriaSource& other);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const &);
};

#endif
