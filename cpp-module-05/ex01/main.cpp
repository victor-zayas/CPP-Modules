#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
		Bureaucrat	test("test", 50);
		Bureaucrat	john("John Doe", 150);
		Bureaucrat	jane("Jane Doe", 1);
		Form		socialSecurity("socialSecurity", 50, 40);
		Form		weaponLicence("weaponLicence", 150, 40);
		//Form		formTooLow("FormTooLow", 151, 40);

		test.signForm(socialSecurity);
		std::cout << socialSecurity << std::endl;
		john.signForm(weaponLicence);
		std::cout << weaponLicence << std::endl;
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
	}
	catch (std::exception &_exception) {
		std::cout << _exception.what() << std::endl;
	}
	return (0);
}
