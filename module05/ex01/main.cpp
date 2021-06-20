#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	try {
		Form form("form", 0, 150);
		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form("form", 5, 151);
		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form("form", 0, 151);
		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form("form", 50, 50);
		Bureaucrat hyungjki("hyungjki", 5);
		hyungjki.signForm(form);
		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form("form", 50, 50);
		Bureaucrat hyungjki("hyungjki", 51);
		hyungjki.signForm(form);
		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}