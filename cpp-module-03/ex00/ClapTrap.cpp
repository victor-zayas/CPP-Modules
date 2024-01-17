#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Nameless"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
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
    std::cout << "This ClapTrap was named: " << this->getName() << std::endl;
}

void    ClapTrap::setEnergyPoints(uint amount) {
    this->_energyPoints = amount;
    std::cout << "ClapTrap " << this->getName() << " has " << this->getEnergyPoints() << " energy points" << std::endl;
}

void    ClapTrap::setHitPoints(uint amount) {
    this->_hitPoints = amount;
    std::cout << "ClapTrap " << this->getName() << " has " << this->getEnergyPoints() << " hit points" << std::endl;
}

void    ClapTrap::setAttackDamage(uint amount) {
    this->_hitPoints = amount;
    std::cout << "ClapTrap " << this->getName() << " has " << this->getAttackDamage() << " attack damage" << std::endl;
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
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->getName() << " haven't enough energy points and can't attack" << std::endl;
        return ;
    }
    else {
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << getName() << " attacks " << target
        << " causing " << getAttackDamage() << " points of damage" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage" << std::endl;
    if (amount >= this->_hitPoints)
        this->~ClapTrap();
    else {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->getName() << " has " << this->_hitPoints
        << " hit points remain" << std::endl;
    }
}
void    ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->getName() << " have " << this->_energyPoints
        << " energy points" << std::endl;
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->getName() << " haven't enough energy points to repair" << std::endl;
        return ;
    }
    else {
        this->_energyPoints -= 1;
        if (this->_hitPoints >= 10) {
            std::cout << "ClapTrap " << this->getName() << " have all hit points" << std::endl;
            return ;
        }
        else if ((this->_hitPoints + amount) >= 10) {
			this->setHitPoints(10);
			std::cout << "ClapTrap " << this->getName() << " repair " << (this->_hitPoints + amount) - 10 << " hit points" << std::endl;
		}
		else
            std::cout << "ClapTrap " << this->getName() << " repair " << this->_hitPoints + amount
            << " hit points" << std::endl;
    }
}
