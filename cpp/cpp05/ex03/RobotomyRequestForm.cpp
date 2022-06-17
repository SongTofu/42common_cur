#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Default Robotomy" , 72, 45), _target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Form" , 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) : Form(other), _target(other._target)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	int success = std::rand() % 2;
	if (this->getIsSigned() == false)
		throw (Form::UnsignedFormException());
	else if(executor.getGrade() > this->getGradeForExec())
		throw (Form:: GradeTooLowException());
	std::cout << "< intensive drilling noises >" << std::endl;
	if (success == 1)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " failed to robotize" << std::endl; //체크
}