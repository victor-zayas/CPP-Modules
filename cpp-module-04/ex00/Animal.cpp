#include "Animal.hpp"

Animal::Animal() {
    this->_type = "Default";
    std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
    this->_type = copy._type;
    std::cout << "Copy constructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Operator constructor called" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor called" << std::endl;
}

void    Animal::setType(std::string newType) {
    this->_type = newType;
}

std::string Animal::getType() const {
    return this->_type;
}

void    Animal::makeSound(void) const {
    std::cout << "Unkwon animal noises" << std::endl;
}
