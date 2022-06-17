#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string	_target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& other);
	RobotomyRequestForm&	operator=(RobotomyRequestForm const& other);
	~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const;
};

#endif