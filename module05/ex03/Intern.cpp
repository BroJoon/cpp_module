#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
static Form*	createShrubberyCreationForm(std::string & target) 
{ 
	return (new ShrubberyCreationForm(target)); 
}

static Form*	createPresidentialPardonForm(std::string & target)
{
	return (new PresidentialPardonForm(target));
}
static Form*	createRobotomyRequestForm(std::string & target)
{
	return (new RobotomyRequestForm(target)); 
}

typedef Form* (*CreateForms)(std::string &);

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = 
    {
        "shrubbery creation",
        "presidential pardon",
        "robotomy request"
    };
	CreateForms createForms[3] = 
	{
		createShrubberyCreationForm,
		createPresidentialPardonForm,
		createRobotomyRequestForm
	};
	for (int i = 0;i < 3;i++)
		if (name == formNames[i])
			return createForms[i](target);
	throw Intern::FormNotFoundException();
	return NULL;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Error: Intern: Form Not Found!";
}
