#include "ICharacter.hpp"

ICharacter::ICharacter(): _name("Default") {
	for (int i=0; i < 4; i++) {
		this->slot[i] = "empty";
	}
	std::cout << "Default constructor called" << std::endl;
};

ICharacter::ICharacter(std::string name) {
	this->_name = name;
	for (int i=0; i < 4; i++) {
		this->slot[i] = "empty";
	}
	std::cout << "ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &copy) {
	this->_name = copy._name;
	std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter	&ICharacter::operator=(const ICharacter &other) {
	if (this != &other) {
		this->_name = other._name;
	}
	std::cout << "Icharacter operator constructor called" << std::endl;
	return *this;
}

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called" << std::endl;
}


std::string	const &ICharacter::getName() const{
	return this->_name;
}

void	ICharacter::equip(AMateria *m) {
	for (int i=0; i < 4; i++) {
		this->slot[i] = m;
	}
	std::cout << "Equip " << m->getType() << " materia" << std::endl;
}

void	ICharacter::unequip(int idx) {
	std::cout << "Unequip " << idx << " materia" << std::endl;
}

void	ICharacter::use(int idx, ICharacter &target) {
	std::cout << target.getName() << " use " << idx << " materia" << std::endl;
}
