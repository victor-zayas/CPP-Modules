#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _attackDamage(0), _energyPoints(10) {
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

void    ClapTrap::setName(std::string name) {
    this->_name = name;
}

void    ClapTrap::setEnergyPoints(uint amount) {
    this->_energyPoints = amount;
}

void    ClapTrap::setHitPoints(uint amount) {
    this->_hitPoints = amount;
}

void    ClapTrap::setAttackDamage(uint amount) {
    this->_attackDamage = amount;
}

std::string ClapTrap::getName() const {
    return this->_name;
}

uint ClapTrap::getHitPoints() const {
    return this->_hitPoints;
}

uint ClapTrap::getEnergyPoints() const {
    return this->_energyPoints;
}

uint ClapTrap::getAttackDamage() const {
    return this->_attackDamage;
}

void    ClapTrap::attack(const std::string &target) {
    if (this->_energyPoints <= 0) {
        std::cout << this->getName() << " haven't enough energy points and can't attack" << std::endl;
        return ;
    }
    else {
        this->_energyPoints -= 1;
        std::cout << this->getName() << " attacks " << target
        << " causing " << this->getAttackDamage() << " points of damage" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << this->getName() << " takes " << amount << " damage" << std::endl;
    if (amount >= this->_hitPoints)
        this->~ClapTrap();
    else {
        this->_hitPoints -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    std::cout << this->getName() << " have " << this->_energyPoints
        << " energy points" << std::endl;
    if (this->_energyPoints <= 0) {
        std::cout << this->getName() << " haven't enough energy points to repair" << std::endl;
        return ;
    }
    else {
        this->_energyPoints -= 1;
        if (this->_hitPoints >= 10) {
            std::cout << this->getName() << " have all hit points" << std::endl;
            return ;
        }
        else if ((this->_hitPoints + amount) >= 10) {
			this->setHitPoints(10);
			std::cout << this->getName() << " repair " << (this->_hitPoints + amount) - 10 << " hit points" << std::endl;
		}
		else
            std::cout << this->getName() << " repair " << this->_hitPoints + amount
            << " hit points" << std::endl;
    }
}
