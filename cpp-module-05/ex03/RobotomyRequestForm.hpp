#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm {
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    const RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    virtual ~RobotomyRequestForm();

    virtual void    execute(const Bureaucrat &executor) const;
};

#endif
