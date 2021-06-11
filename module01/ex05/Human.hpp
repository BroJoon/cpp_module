#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"
#include <iostream>

class Human
{
	private:
		Brain brain;

	public:
		const Brain& getBrain() const;
		std::string identify() const;
};

#endif