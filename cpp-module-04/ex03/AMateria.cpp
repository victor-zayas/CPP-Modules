#include "AMateria.hpp"

AMateria::AMateria(): _type("Undefined") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
	this->_type = copy._type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other) {
	  if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "AMateria operator constructor called" << std::endl;
    return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

void	AMateria::setType(std::string type) {
	this->_type = type;
}

std::string	const	&AMateria::getType() const {
	return this->_type;
}

AMateria	*AMateria::clone() const {
	std::cout << "Matter cloned" << std::endl;
}

void AMateria::use(ICharacter &target) {
	std::cout << target.getName() << " cast " << this->_type << " spell" << std::endl;
}
