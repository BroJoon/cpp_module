#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form("Shrubbery Creation Form", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	Form::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	std::string tree = "";
	tree.append("                                                                \n");
	tree.append("		          .     .  .      +     .      .          .      \n");
	tree.append("     .       .      .     #       .           .                 \n");
	tree.append("        .      .         ###            .      .      .         \n");
	tree.append("      .      .   ##:. .:#####:. .:##  .      .                  \n");
	tree.append("          .      . ###############  .                           \n");
	tree.append("       .     ##:.    .:#######:.    .:##  .        .       .    \n");
	tree.append("  .             #####################        .        .         \n");
	tree.append("        .    ##:.  ###############  .:##   .       .            \n");
	tree.append("     .     .  #########################                  .      \n");
	tree.append("                .###################           .      .         \n");
	tree.append("    .   #:. ...  .:###############:.  ... .:#     .             \n");
	tree.append("      .     #############################      .     .          \n");
	tree.append("    .    .     #######################    .      .              \n");
	tree.append("            .     .      000      .    .     .                  \n");
	tree.append("       .         .   .   000     .        .       .             \n");
	tree.append(".. .. ..................O000O........................ ...... ...\n");

	std::ofstream ofs(getTarget() + "_shrubbery");
	if (!ofs.is_open())
		throw ShrubberyCreationForm::fileOpenFailed();
	ofs << tree;
	ofs.close();
}

const char *ShrubberyCreationForm::fileOpenFailed::what() const throw()
{
	return "Error: ShrubberyCreationForm: Opening File Failed!";
}