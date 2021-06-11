#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "pinter: " << *ptr << std::endl;
	std::cout << "reference: " << ref << std::endl;
	return (0);
}