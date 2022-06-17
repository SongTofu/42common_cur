#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

static Form	*new_robo(std::string target)
{
	Form	*robo = new RobotomyRequestForm(target);
	return (robo);
}

static Form	*new_president(std::string target)
{
	Form	*president = new PresidentialPardonForm(target);
	return (president);
}

static Form	*new_shrub(std::string target)
{
	Form	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

Form *Intern::makeForm(std::string formName, std::string formTarget)
{
	Form	*(*fct[3])(std::string target) = { new_robo, new_president, new_shrub};
	std::string	msg[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form	*ret = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName == msg[i])
			ret = fct[i](formTarget);
	}
	if (ret)
		std::cout << "Intern creates " << *ret << std::endl;
	else
		throw (Intern::Exception());
	return (ret);
}

const char* Intern::Exception::what() const throw()
{
	return ("Unknown Form exception");
}