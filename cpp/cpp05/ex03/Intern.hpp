#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{
public:
	Intern();
	Form	*makeForm(std::string formName, std::string formTarget);
	Intern(Intern const& other);
	Intern&	operator=(Intern const& other);
	~Intern();

	class Exception : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif