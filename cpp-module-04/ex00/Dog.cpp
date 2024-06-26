#include "Dog.hpp"

Dog::Dog() {
    this->_type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(std::string name) {
    this->_type = name;
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) {
    this->_type = copy._type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog  &Dog::operator=(const Dog &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Dog operator constructor called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "barks barks barks barks" << std::endl;
}
