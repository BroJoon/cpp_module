#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Character
{
private:
	std::string name;
	int ap;
	AWeapon* weapon;
public:
	Character();
	Character(std::string const &name);
	Character(const Character &character);

	~Character();

	Character &operator=(const Character &character);


	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);

	std::string const &getName() const;
	int getAP();
	AWeapon const *getWeapon() const;
};

std::ostream& operator<<(std::ostream &stream, Character &character);

#endif