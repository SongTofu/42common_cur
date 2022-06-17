#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class Form;

class ShrubberyCreationForm : public Form
{
private:
	std::string	_target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& other);
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& other);
	~ShrubberyCreationForm();

	std::string	getTarget() const;

	void execute(Bureaucrat const & executor) const;
};

#endif