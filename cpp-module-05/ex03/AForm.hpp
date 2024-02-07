#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _signed;
    const unsigned int  _grade;
    const unsigned int  _exec;

public:
    AForm();
    AForm(std::string name, unsigned int grade, unsigned int exec);
    AForm(const AForm &copy);
    const AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string		getName()const;
    bool    		getSigned()const;
    unsigned int    getGrade()const;
    unsigned int    getExec()const;

    void    beSigned(Bureaucrat &bureaucrat);
    virtual void    execute(const Bureaucrat &executor) const = 0;

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

    class NotSignedException : public std::exception {
    public:
        const char *what() const throw() {
            return ("Form not signed");
        }
    };
};

std::ostream	&operator<<(std::ostream &_ostream, const AForm &_form);

#endif
