#ifndef CAT_HPP
#define CAT_HPP

#include "Victim.hpp"
#include <iostream>

class Cat : public Victim
{
	protected:
		Cat();
	public:
		Cat(std::string cat);
		Cat(const Cat &cat);
		virtual ~Cat();
		Cat& operator=(const Cat &cat);

		virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &stream, Cat &cat);

#endif