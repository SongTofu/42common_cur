#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Default Presidential", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Form", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) : Form(other), _target(other._target)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeForExec())
		throw (Form::GradeTooLowException());
	else
		std::cout << this->_target << " was pardonned by Zafod Beeblebrox" << std::endl;
}