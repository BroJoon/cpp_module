#include "Brain.hpp"
#include <iostream>

std::string Brain::identify() const
{
	std::stringstream strstream;
	strstream << "0x" << std::uppercase << std::hex << (long)this;
	return (strstream.str());
}