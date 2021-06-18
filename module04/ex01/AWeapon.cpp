#include "AWeapon.hpp"

AWeapon::AWeapon()
{
	name = "";
	damage = 0;
	apcost = 0;
}

AWeapon::AWeapon(const AWeapon &weapon)
{
	name = weapon.name;
	damage = weapon.damage;
	apcost = weapon.apcost;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::~AWeapon()
{

}

AWeapon &AWeapon::operator=(const AWeapon &weapon)
{
	name = weapon.name;
	damage = weapon.damage;
	apcost = weapon.apcost;
	return *this;
}

std::string const &AWeapon::getName() const
{
	return name;
}

int AWeapon::getAPCost() const
{
	return apcost;
}

int AWeapon::getDamage() const
{
	return damage;
}
