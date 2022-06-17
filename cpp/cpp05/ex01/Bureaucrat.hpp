#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

# define	MIN_GRADE	150
# define	MAX_GRADE	1

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;
	Bureaucrat();
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat const& other);
	Bureaucrat&	operator=(Bureaucrat const& other);
	~Bureaucrat();

	const std::string	getName() const;
	int	getGrade() const;
	void	incrementGrade(int change);
	void	decrementGrade(int change);
	void	signForm(Form& form) const;

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
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &B);

#endif