#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &plasmaRifle);
	virtual ~PlasmaRifle();
	PlasmaRifle &operator=(const PlasmaRifle &plasmaRifle);
	virtual void attack() const;
};

#endif
