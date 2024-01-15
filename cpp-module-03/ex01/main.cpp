#include "ScavTrap.hpp"

int main(void) {
    ClapTrap    JoaquinJavier("Jokin");
    ScavTrap    ManuelFerran("Manu");

    std::cout << std::endl;
    JoaquinJavier.attack("Manu");
    ManuelFerran.takeDamage(0);
    ManuelFerran.guardGate();
    std::cout << "ScavTrap " << ManuelFerran.getName() << " is now very angry" << std::endl;
    ManuelFerran.attack("Jokin");
    JoaquinJavier.takeDamage(20);
    std::cout << std::endl;

    // ScavTrap    paco("paco");
}
