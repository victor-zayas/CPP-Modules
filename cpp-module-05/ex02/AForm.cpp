#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(0), _grade(1), _exec(1) {}

AForm::AForm(std::string name, unsigned int grade, unsigned int exec): _name(name), _signed(0), _grade(grade), _exec(exec) {
    if (this->_grade > 150)
        throw GradeTooLowException();
    if (this->_grade < 1)
        throw GradeTooHighException();
    if (this->_exec > 150)
        throw GradeTooLowException();
    if (this->_exec < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &copy): _name(copy.getName()), _signed(copy.getSigned()), _grade(getGrade()), _exec(getExec()) {}

const AForm    &AForm::operator=(const AForm &other) {
     if (this != &other) {
        this->_signed = other.getSigned();
    }
    return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return (this->_name);
}

bool    AForm::getSigned() const {
    return (this->_signed);
}

unsigned int    AForm::getGrade() const {
    return (this->_grade);
}

unsigned int    AForm::getExec() const {
    return (this->_exec);
}

void    AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->getGrade())
        throw   GradeTooLowException();
    this->_signed = 1;
}

std::ostream	&operator<<(std::ostream &ostream, const AForm &form) {
	ostream << "Form: " << form.getName() << ", Form grade: " << form.getGrade();
	return (ostream);
}
