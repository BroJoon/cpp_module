#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	PowerFist(const PowerFist &powerFist);
	virtual ~PowerFist();
	PowerFist &operator=(const PowerFist &powerFist);
	virtual void attack() const;
};

#endif
