
#include "humanB.hpp"

// HumanB::HumanB(): _name("name"), weapon() {}

HumanB::HumanB(std::string name): _name(name){
    this->weapon = new Weapon("default");
}

HumanB::HumanB(const HumanB &copy) {
    _name = copy._name;
    weapon = copy.weapon;
}

HumanB  &HumanB::operator=(const HumanB &other) {
    if (this != &other) {
        _name = other._name;
        weapon = other.weapon;
    }
    return *this;
}

HumanB::~HumanB() {
    delete this->weapon;
}

void    HumanB::setName(std::string name) {
    this->_name = name;
}

void    HumanB::setWeapon(std::string weapon) {
    this->weapon->setType(weapon);
}

const   std::string HumanB::getName() {
    return _name;
}

void    HumanB::attack() {
    if (this->weapon)
        std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}
