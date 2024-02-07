#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string   _name;
    bool                _signed;
    const unsigned int  _grade;
    const unsigned int  _exec;

public:
    Form();
    Form(std::string name, unsigned int grade, unsigned int exec);
    Form(const Form &copy);
    Form &operator=(const Form &other);
    ~Form();

    std::string		getName()const;
    bool    		getSigned()const;
    unsigned int    getGrade()const;
    unsigned int    getExec()const;

    void    beSigned(Bureaucrat &bureaucrat);

    class GradeTooLowException : public std::exception {
	public:
		const char	*what() const throw() {
			return ("Grade too low");
		}
	};

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return ("Grade too high");
		}
	};

};

std::ostream	&operator<<(std::ostream &_ostream, const Form &_form);

#endif
