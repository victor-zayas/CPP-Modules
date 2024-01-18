#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->_type = "Default";
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    this->_type = copy._type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "WrongAnimal operator constructor called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::setType(std::string newType) {
    this->_type = newType;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}

void    WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal sound" << std::endl;
}
