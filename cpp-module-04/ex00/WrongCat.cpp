#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->_type = "Default";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) {
    this->_type = name;
    std::cout << "WrongCat Wrongcat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
    this->_type = copy._type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat  &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "WrongCat operator constructor called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Wrongcat destructor called" << std::endl;
}

void    WrongCat::makeSound() const {
    std::cout << "WrongCat sounds" << std::endl;
}
