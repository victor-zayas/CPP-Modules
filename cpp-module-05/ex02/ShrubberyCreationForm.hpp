#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubbeyCreationForm: public AForm {
private:
    std::string _target;

public:
    ShrubbeyCreationForm();
    ShrubbeyCreationForm(std::string target);
    ShrubbeyCreationForm(const ShrubbeyCreationForm &copy);
    const ShrubbeyCreationForm &operator=(const ShrubbeyCreationForm &other);
    virtual ~ShrubbeyCreationForm();

    virtual void    execute(const Bureaucrat &executor) const;
};

#endif
