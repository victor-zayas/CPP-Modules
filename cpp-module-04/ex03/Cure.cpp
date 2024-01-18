#include "Cure.hpp"

Cure::Cure(): _type("Unknown") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string type): _type("cure") {
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) {
	this->_type = copy._type;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure	&Cure::operator=(const Cure &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << "Cure operator constructor called" << std::endl;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

std::string	Cure::getType() {
	return this->_type;
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria	*Cure::clone() const {
	return new Cure();
}
