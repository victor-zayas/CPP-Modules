#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name), _grade(grade) {
    if (_grade < 1)
		throw BureaucratHighException();
	if (_grade > 150)
		throw BureaucratLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

unsigned int    Bureaucrat::getGrade() const {
    return (this->_grade);
}

void    Bureaucrat::gradeIncrement() {
    if ((this->getGrade() - 1) < 1)
        throw	BureaucratHighException();
    this->_grade--;
}

void    Bureaucrat::gradeDecrement() {
    if ((this->getGrade() + 1) > 150)
        throw   BureaucratLowException();
    this->_grade++;
}

std::ostream	&operator<<(std::ostream &_ostream, const Bureaucrat &_bureaucrat) {
	_ostream << "Bureaucrat: " << _bureaucrat.getName() << ", Bureaucrat grade: " << _bureaucrat.getGrade();
	return (_ostream);
}
