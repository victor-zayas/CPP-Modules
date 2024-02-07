#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) {
    this->_target = copy._target;
}

const   RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getExec())
        throw GradeTooLowException();
    if (!this->getSigned())
        throw NotSignedException();
    std::cout << "Making some drilling noises...\n";
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed for " << _target << "\n";
}
