#include "Form.hpp"

Form::Form() : _name("undefine"), _gradeSign(150), _gradeExec(150), _signed(0)
{
	std::cout << "A default " << *this << " has been constructed" << std::endl;
}

Form::~Form()
{
	std::cout << *this << " has beed destroyed\n";
}

Form::Form(const std::string name, const int sign, const int exec) : _name(name), _gradeSign(sign), _gradeExec(exec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(Form const& other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _signed(other._signed)
{
}

Form&	Form::operator=(Form const& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

const std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_signed);
}

int	Form::getGradeForSign() const
{
	return (_gradeSign);
}

int	Form::getGradeForExec() const
{
	return (_gradeExec);
}

void	Form::beSigned(Bureaucrat const& B)
{
	if (B.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	if (getIsSigned())
		throw Form::AlreadySignedException();
	_signed = true;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "<Form> grade too low!";
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "<Form> grade too high!";
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return "<Form> cannot sign a form twice!";
}

const char* Form::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
}

std::ostream	&operator<<(std::ostream &out, Form const& F)
{
	out << "Form " << F.getName() << " having a grade_to_sign " << F.getGradeForSign() << " and a grade_to_execute "
		<< F.getGradeForExec() << " with signed equal to " << F.getIsSigned();
	return (out);
}