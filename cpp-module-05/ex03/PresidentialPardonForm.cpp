#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) {
    this->_target = copy._target;
}

const   PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getExec())
        throw GradeTooLowException();
    if (!this->getSigned())
        throw NotSignedException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
