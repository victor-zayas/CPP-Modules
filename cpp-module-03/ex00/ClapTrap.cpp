#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Nameless"), _hitPoints(10), _attackDamage(0), _energyPoints(10) {
    std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name), _hitPoints(10), _attackDamage(0), _energyPoints(10) {
    std::cout << "ClapTrap " << this->getName() << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _attackDamage = other._attackDamage;
        _energyPoints = other._energyPoints;
    }
    std::cout << "Copy assignment constructor called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->getName() << " destroyed" << std::endl;
}

std::string ClapTrap::getName() {
    return this->_name;
}

uint ClapTrap::getHitPoints() {
    return this->_hitPoints;
}

uint ClapTrap::getEnergyPoints() {
    return this->_energyPoints;
}

uint ClapTrap::getAttackDamage() {
    return this->_attackDamage;
}

void    ClapTrap::attack(const std::string &target) {
    std::cout << "ClapTrap " << getName() << " attacks " << target
        << " causing " << getAttackDamage() << " points of damage" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage" << std::endl;
}
void    ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->getName() << " repair " << amount << " hit points" << std::endl;
}

//TODO: check health on takedamage and repaired