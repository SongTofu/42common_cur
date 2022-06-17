#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrubbery" , 145, 137), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrub Form", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : Form(other), _target(other._target)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	tree = 
"     ccee88oo          \n"
"  C8O8O8Q8PoOb o8oo    \n"
" dOB69QO8PdUOpugoO9bD  \n"
"CgggbU8OU qOp qOdoUOdcb\n"
"   6OuU  /p u gcoUodpP \n"
"      \\\\//  /douUP   \n"
"        \\\\////       \n"
"         |||/\\        \n"
"         |||\\/        \n"
"         |||||         \n"
"  .....\\//||||\\....  \n";

	if (this->getIsSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeForExec())
		throw (Form::GradeTooLowException());
	std::ofstream file(_target + "__shrubbery");
	if (file.is_open() == false)
		throw (std::ofstream::failure("Fialed to open " + this->_target + "_shrubbery\n"));
	file << tree;
	file.close();
}