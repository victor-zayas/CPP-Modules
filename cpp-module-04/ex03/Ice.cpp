#include "Ice.hpp"

Ice::Ice(): _type("Unknown") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string type): _type("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) {
	this->_type = copy._type;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << "Ice operator constructor called" << std::endl;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

std::string	Ice::getType() {
	return this->_type;
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone() const {
	return new Ice();
}
