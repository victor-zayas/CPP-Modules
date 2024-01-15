#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->setName("Default");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
    std::cout << "FragTrap " << this->getName() << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy) {
    std::cout << "Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        setName(other.getName());
        setHitPoints(other.getHitPoints());
        setEnergyPoints(other.getEnergyPoints());
        setAttackDamage(other.getAttackDamage());
    }
    std::cout << "Copy assignment constructor called" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destroyed" << std::endl;
}

void    FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->getName() << " is hivefiving with other FragTrap" << std::endl;
}
