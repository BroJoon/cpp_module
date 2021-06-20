#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>

int main()
{
    srand(time(NULL));
    Intern intern;
    Form *form;
    Bureaucrat hyungjki("hyungjki", 1);
    try {
        form = intern.makeForm("empty", "empty");
        hyungjki.signForm(*form);
        hyungjki.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        form = intern.makeForm("shrubbery creation", "shrubbery creation");
        hyungjki.signForm(*form);
        hyungjki.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        delete form;
    }
    try {
        form = intern.makeForm("presidential pardon", "presidential pardon");
        hyungjki.signForm(*form);
        hyungjki.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        delete form;
    }
    try {
        form = intern.makeForm("robotomy request", "robotomy request");
        hyungjki.signForm(*form);
        hyungjki.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        delete form;
    }

    return (0);
}