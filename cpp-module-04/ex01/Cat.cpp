#include "Cat.hpp"

Cat::Cat() {
    this->_type = "Default";
    this->_brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string name) {
    this->_type = name;
    this->_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) {
    this->_type = copy._type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat  &Cat::operator=(const Cat &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Cat operator constructor called" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "meows meows meows meows" << std::endl;
}
