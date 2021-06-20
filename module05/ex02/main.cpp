#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	try {
		ShrubberyCreationForm form("target");
		std::cout << form;
		Bureaucrat hyungjki("hyungjki", 1);
		hyungjki.signForm(form);
		hyungjki.signForm(form);
		hyungjki.executeForm(form);
		hyungjki.executeForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		PresidentialPardonForm form("target");
		std::cout << form;
		Bureaucrat hyungjki("hyungjki", 1);
		hyungjki.signForm(form);
		hyungjki.signForm(form);
		hyungjki.executeForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		RobotomyRequestForm form("target");
		std::cout << form;
		Bureaucrat hyungjki("hyungjki", 1);
		hyungjki.signForm(form);
		hyungjki.signForm(form);
		hyungjki.executeForm(form);
		hyungjki.executeForm(form);
		hyungjki.executeForm(form);
		hyungjki.executeForm(form);
		hyungjki.executeForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		RobotomyRequestForm form("target");
		std::cout << form;
		Bureaucrat hyungjki("hyungjki", 150);
		hyungjki.signForm(form);
		hyungjki.executeForm(form);
		Bureaucrat hyungjki2("hyungjki2", 72);
		hyungjki2.signForm(form);
		Bureaucrat hyungjki3("hyungjki3", 45);
		hyungjki3.executeForm(form);
		Bureaucrat hyungjki4("hyungjki4", 46);
		hyungjki4.executeForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}