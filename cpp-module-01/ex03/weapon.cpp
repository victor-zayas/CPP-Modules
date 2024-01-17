
#include "Weapon.hpp"

Weapon::Weapon(const std::string weaponType): _type(weaponType) {}

Weapon::Weapon(const Weapon &copy) {
    _type = copy._type;
}

Weapon  &Weapon::operator=(const Weapon &other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Weapon::~Weapon() {}

void    Weapon::setType(std::string newType) {
    this->_type = newType;
}

const std::string Weapon::getType() {
    return _type;
}
