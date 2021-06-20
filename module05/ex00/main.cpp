#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat burcat("hyungjki", 0);
		std::cout << burcat;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat burcat("hyungjki", 151);
		std::cout << burcat;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat burcat("hyungjki", 1);
		burcat.decrement();
		std::cout << burcat;
		burcat.increment();
		std::cout << burcat;
		burcat.increment();
		std::cout << burcat;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat burcat("hyungjki", 150);
		burcat.increment();
		std::cout << burcat;
		burcat.decrement();
		std::cout << burcat;
		burcat.decrement();
		std::cout << burcat;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}