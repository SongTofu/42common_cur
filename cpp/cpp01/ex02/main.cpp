#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << std::endl;
	
	std::cout << "Address of the string: " << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "string address: " << &str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of the string: " << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "string itself: " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	
	std::cout << std::endl;

}