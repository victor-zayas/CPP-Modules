#include "ShrubberyCreationForm.hpp"

ShrubbeyCreationForm::ShrubbeyCreationForm(): _target("Default") {}

ShrubbeyCreationForm::ShrubbeyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubbeyCreationForm::ShrubbeyCreationForm(const ShrubbeyCreationForm &copy) {
    this->_target = copy._target;
}

const   ShrubbeyCreationForm   &ShrubbeyCreationForm::operator=(const ShrubbeyCreationForm &other) {
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

ShrubbeyCreationForm::~ShrubbeyCreationForm() {}

void    ShrubbeyCreationForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getExec())
        throw GradeTooLowException();
    if (!this->getSigned())
        throw NotSignedException();
    std::ofstream	targetFile((this->_target + "_shrubbery").c_str());
	if (!targetFile.is_open()) {
		std::cerr << "Error: No se pudo abrir el archivo para escritura" << std::endl;
		return;
	}
	targetFile << "       _-_" << std::endl;
	targetFile << "   / ~~   ~~ \\" << std::endl;
	targetFile << " /~~         ~~\\" << std::endl;
	targetFile << "{               }" << std::endl;
	targetFile << " \\  _-     -_  /" << std::endl;
	targetFile << "   ~  \\\\ //  ~" << std::endl;
	targetFile << "_- -   | | _- _" << std::endl;
	targetFile << "  _ -  | |   -_" << std::endl;
	targetFile << "      // \\\\" << std::endl;
	targetFile.close();
}
