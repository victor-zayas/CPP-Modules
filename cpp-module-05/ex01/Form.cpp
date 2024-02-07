#include "Form.hpp"

Form::Form(): _name("Default"), _signed(0), _grade(1), _exec(1) {}

Form::Form(std::string name, unsigned int grade, unsigned int exec): _name(name), _signed(0), _grade(grade), _exec(exec) {
    if (this->_grade > 150)
        throw GradeTooLowException();
    if (this->_grade < 1)
        throw GradeTooHighException();
    if (this->_exec > 150)
        throw GradeTooLowException();
    if (this->_exec < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &copy): _name(copy.getName()), _signed(copy.getSigned()), _grade(getGrade()), _exec(getExec()) {}

Form    &Form::operator=(const Form &other) {
     if (this != &other) {
        this->_signed = other.getSigned();
    }
    return (*this);
}

Form::~Form() {}

std::string Form::getName() const {
    return (this->_name);
}

bool    Form::getSigned() const {
    return (this->_signed);
}

unsigned int    Form::getGrade() const {
    return (this->_grade);
}

unsigned int    Form::getExec() const {
    return (this->_exec);
}

void    Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->getGrade())
        throw   GradeTooLowException();
    this->_signed = 1;
}

std::ostream	&operator<<(std::ostream &_ostream, const Form &_form) {
	_ostream << "Form: " << _form.getName() << ", Form grade: " << _form.getGrade();
	return (_ostream);
}
