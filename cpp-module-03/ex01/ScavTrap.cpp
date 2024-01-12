
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->setName("Default");
	this->setHitpoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap constructor called" << this->getName() << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        _name = other._name;
        _hitpoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "Copy assignment constructor called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed" << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " p is now in Gate keeper mode" << std::endl;
}
