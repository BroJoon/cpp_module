#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon
{
protected:
	std::string name;
	int damage;
	int apcost;
public:
	AWeapon();
	AWeapon(const AWeapon &weapon);
	AWeapon(std::string const &name, int apcost, int damage);
	virtual ~AWeapon();
	AWeapon &operator=(const AWeapon &weapon);

	std::string const &getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};

#endif
