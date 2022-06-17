#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int	_gradeSign; //싸인
	const int	_gradeExec; //실행
	bool	_signed;
	Form();
public:
	Form(const std::string name, const int sign, const int exec);
	Form(Form const& other);
	Form&	operator=(Form const& other);
	virtual ~Form();

	const std::string	getName() const;
	bool	getIsSigned() const;
	int	getGradeForSign() const;
	int	getGradeForExec() const;
	void	beSigned(Bureaucrat const& B);

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class UnsignedFormException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form& F);

#endif