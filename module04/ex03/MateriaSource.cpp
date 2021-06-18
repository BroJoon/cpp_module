#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0;i < 4;i++)
		array[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for(int i = 0;i < 4;i++)
		array[i] = NULL;
	operator=(other);
}

MateriaSource::~MateriaSource()
{
	for(int i = 0;i < 4;i++)
		if(array[i])
			delete array[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for(int i = 0;i < 4;i++)
		if(array[i])
			delete array[i];
	for(int i = 0;i < 4;i++)
		array[i] = other.array[i] ? other.array[i]->clone() : NULL;

	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for(int i = 0;i < 4;i++)
	{
		if (!array[i])
		{
			array[i] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0;i < 4;i++)
	{
		if (array[i] && array[i]->getType() == type)
			return array[i]->clone();
	}
	return NULL;
}