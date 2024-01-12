#include "ScavTrap.hpp"

int main(void) {
    ClapTrap    JoaquinJavier("Jokin");
    ScavTrap    ManuelFerran("Manu");

    std::cout << std::endl;
    JoaquinJavier.attack("Luis");
    ManuelFerran.takeDamage(0);
    ManuelFerran.guardGate();
    std::cout << "ScavTrap" << ManuelFerran.getName() << " is now very angry" << std::endl;
    std::cout << std::endl;
}

