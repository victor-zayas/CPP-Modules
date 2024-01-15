#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    this->_name = "Default";
    ClapTrap::setName("Defualt_clap_name");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
    std::cout << "Default DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
    this->_name = name;
    ClapTrap::setName(name + "_clap_name");
    this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap " << this->getName() << " created" << std::endl;
    std::cout << "DiamondTrap " << this->getHitPoints() << " created" << std::endl;
    std::cout << "DiamondTrap " << this->getEnergyPoints() << " created" << std::endl;
    std::cout << "DiamondTrap " << this->getAttackDamage() << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
    std::cout << "Copy constructor called" << std::endl;
}

DiamondTrap    &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        setName(other.getName());
        setHitPoints(other.getHitPoints());
        setEnergyPoints(other.getEnergyPoints());
        setAttackDamage(other.getAttackDamage());
    }
    std::cout << "Copy assignment constructor called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destroyed" << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "Who am I?" << std::endl;
    std::cout << this->_name << std::endl;
    std::cout << "or" << std::endl;
    std::cout << ClapTrap::getName() << std::endl;
}
