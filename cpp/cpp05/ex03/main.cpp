#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	srand(time(NULL));
	Intern	intern;
	Form	*robo_form;
	Form	*shrub_form;
	Form	*president_form;
	Form	*unknown_form;
	std::cout << std::endl << std::endl;

	std::cout << "INTERN TESTS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		robo_form = intern.makeForm("robotomy request", "robo");
		president_form = intern.makeForm("presidential pardon", "president");
		shrub_form = intern.makeForm("shrubbery creation", "shrub");
		unknown_form = intern.makeForm("driving licence", "drive");
	}
	catch (Intern::Exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	delete robo_form;
	delete shrub_form;
	delete president_form;
	delete unknown_form;
	return (0);
	//-------------------------------------------------------	
}