
#include "HumanA.hpp"

// HumanA::HumanA(): _name("name"), weapon("default") {}

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), weapon(weapon) {}

HumanA::HumanA(const HumanA &copy): _name(copy._name), weapon(copy.weapon) {}

HumanA  &HumanA::operator=(const HumanA &other) {
    if (this != &other) {
        _name = other._name;
        weapon = other.weapon;
    }
    return *this;
}

HumanA::~HumanA() {}

void    HumanA::setName(std::string name) {
    this->_name = name;
}

const   std::string HumanA::getName() {
    return _name;
}

void    HumanA::attack() {
    std::cout << getName() << " attacks with their " << weapon.getType() << std::endl;
}
