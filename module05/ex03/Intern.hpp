#ifndef Intern_hpp
#define Intern_hpp

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern&);
	virtual ~Intern();

	Intern &operator=(const Intern&);

	Form* makeForm(std::string,std::string);

	class FormNotFoundException : public std::exception
	{
	public:
		 virtual const char* what() const throw();
	};
};

#endif
