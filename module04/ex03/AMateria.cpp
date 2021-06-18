#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "";
	xp = 0;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	xp = 0;
}

AMateria::AMateria(const AMateria& other)
{
	type = other.type;
	xp = other.xp;
}

AMateria::~AMateria()
{

}

AMateria &AMateria::operator=(const AMateria& other)
{
	if (type == other.type)
		xp = other.xp;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

unsigned int AMateria::getXP() const
{
	return xp;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	xp += 10;
}
