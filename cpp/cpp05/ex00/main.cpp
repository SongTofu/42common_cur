#include "Bureaucrat.hpp"

int	main() {
	std::cout << "=====constructor=====" << std::endl;

	try {
		Bureaucrat	apple("apple", 1);
		std::cout << apple;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	banana("banana", -42);
		std::cout << banana;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	try {
		Bureaucrat	banana("banana", 4242);
		std::cout << banana;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "=====increment=====" << std::endl;

	try {
		Bureaucrat	apple("apple", 12);
		std::cout << apple;
		apple.incrementGrade(10);
		std::cout << apple;
		apple.incrementGrade(1);
		std::cout << apple;
		apple.incrementGrade(1); // too high!
		std::cout << apple;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "=====decrement=====" << std::endl;

	try {
		Bureaucrat	apple("apple", 139);
		std::cout << apple;
		apple.decrementGrade(10);
		std::cout << apple;
		apple.decrementGrade(1);
		std::cout << apple;
		apple.decrementGrade(1); // too low!
		std::cout << apple;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}