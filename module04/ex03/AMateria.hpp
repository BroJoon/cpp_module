#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;
#include <string>

class AMateria
{
protected:
	std::string type;
	unsigned int xp;
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria& other);
	virtual ~AMateria();

	AMateria &operator=(const AMateria& other);

	std::string const &getType() const;
	unsigned int getXP() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif