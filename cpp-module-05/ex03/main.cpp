#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try {
		Intern Luis;
		AForm *shrubbery;
		AForm *robotomy;
		AForm *presidential;
		AForm *nonexistent;
		Bureaucrat Manuel("Bureaucrat", 1);

		shrubbery = Luis.makeForm("shrubbery", "Home");
		robotomy = Luis.makeForm("robotomy", "Bender");
		presidential = Luis.makeForm("presidential", "someone");
		nonexistent = Luis.makeForm("tax_evasion", "nonexistent");

		Manuel.signForm(*shrubbery);
		Manuel.signForm(*robotomy);
		Manuel.signForm(*presidential);
		Manuel.signForm(*nonexistent);
		Manuel.executeForm(*shrubbery);
		Manuel.executeForm(*robotomy);
		Manuel.executeForm(*presidential);
		Manuel.executeForm(*nonexistent);
	}
	catch (std::exception &_exception) {
		std::cout << _exception.what() << std::endl;
	}
	return (0);
}
