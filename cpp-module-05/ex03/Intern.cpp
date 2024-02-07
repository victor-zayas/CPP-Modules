#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm   *Intern::makeForm(const std::string &name, const std::string &target) {
    AForm   *newForm;
    std::string array[] = {"shrubbery", "robotomy", "presidential"};
    unsigned int    index = 0;

    while (index < 3) {
        if (name == array[index])
            break;
        index++;
    }
    switch (index) {
        case (0): {
            std::cout << "Intern creates " << name << std::endl;
            return (newForm = new ShrubbeyCreationForm(target), newForm);
        }
        case (1): {
            std::cout << "Intern creates " << name << std::endl;
            return (newForm = new RobotomyRequestForm(target), newForm);
        }
        case (2): {
            std::cout << "Intern creates " << name << std::endl;
            return (newForm = new PresidentialPardonForm(target), newForm);
        }
        default: {
            std::cout << "That Aform doesn't exist" << std::endl;
            return (NULL);
        }
    }
}
