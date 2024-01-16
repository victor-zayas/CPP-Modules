#include "Dog.hpp"

Dog::Dog() {
    this->_type = "Default";
    this->_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name) {
    this->_type = name;
    this->_brain = new Brain();
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
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "Dog barks" << std::endl;
}
