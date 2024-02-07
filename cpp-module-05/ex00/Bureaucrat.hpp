#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string _name;
    unsigned int	_grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

	std::string	getName(void)const;
	unsigned int	getGrade(void)const;

	void	gradeIncrement(void);
	void	gradeDecrement(void);

	class BureaucratLowException : public std::exception {
	public:
		const char	*what() const throw() {
			return ("Grade too low");
		}
	};

	class BureaucratHighException : public std::exception {
	public:
		const char *what() const throw() {
			return ("Grade too high");
		}
	};
};

std::ostream	&operator<<(std::ostream &_ostream, const Bureaucrat &_bureaucrat);

#endif
