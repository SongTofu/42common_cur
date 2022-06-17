#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (_grade < MAX_GRADE)
		throw GradeTooHighException();

}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(int change)
{
	if (_grade - change < MAX_GRADE)
		throw GradeTooHighException();
	_grade -=change;
}

void	Bureaucrat::decrementGrade(int change)
{
	if (_grade + change > MIN_GRADE)
		throw GradeTooLowException();
	_grade += change;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeToo *High* Exception");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeToo *Low* Exception");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &B)
{
	out << B.getName() << " , bureaucrat of grade " << B.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(Form& F) const
{
	try {
		F.beSigned(*this);
		std::cout << _name << " signs " << F.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout	<< _name << " cannot sign " << F.getName() << " because "
					<< e.what() << std::endl;
	}
}