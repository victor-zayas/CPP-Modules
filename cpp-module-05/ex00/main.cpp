
#include "Bureaucrat.hpp"

int main(void) {
    try {
		Bureaucrat	test("test", 50);
		Bureaucrat	john("John Doe", 150);
		Bureaucrat	jane("Jane Doe", 1);
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
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	return (0);
}
