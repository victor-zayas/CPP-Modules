#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try {
		Bureaucrat	test("test", 50);
		Bureaucrat	john("John Doe", 150);
		Bureaucrat	jane("Jane Doe", 1);
		AForm	*shrubbery = new ShrubbeyCreationForm("shrubbery");
		AForm	*robotomy = new RobotomyRequestForm("robotomy");
		AForm	*presidential = new PresidentialPardonForm("presidential");

		std::cout << "--- Example of ShrubberyCreationForm ---" << std::endl;
		jane.signForm(*shrubbery);
		jane.executeForm(*shrubbery);
		std::cout << "--- Example of RobotomyRequestForm ---" << std::endl;
		jane.signForm(*robotomy);
		jane.executeForm(*robotomy);
		std::cout << "--- Example of PresidentialPardonForm ---" << std::endl;
		jane.signForm(*presidential);
		jane.executeForm(*presidential);
		std::cout << "----- General tests -----" << std::endl;
		std::cout << test << std::endl;
		test.gradeDecrement();
		std::cout << test << std::endl;
		test.gradeIncrement();
		std::cout << test << std::endl;
		test.gradeIncrement();
		std::cout << test << std::endl;
		std::cout << "----- Too low exceptions -----" << std::endl;
		std::cout << john << std::endl;
		john.gradeDecrement();
		std::cout << john << std::endl;
		std::cout << "----- Too high exceptions -----" << std::endl;
		std::cout << jane << std::endl;
		jane.gradeIncrement();
		std::cout << jane << std::endl;
		delete shrubbery;
		delete robotomy;
		delete presidential;
	}
	catch (std::exception &_exception) {
		std::cout << _exception.what() << std::endl;
	}
	return (0);
}
