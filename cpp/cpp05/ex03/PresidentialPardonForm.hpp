#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string	_target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& other);
	PresidentialPardonForm&	operator=(PresidentialPardonForm const& other);

	~PresidentialPardonForm();
	void execute(Bureaucrat const & executor) const;
};

#endif