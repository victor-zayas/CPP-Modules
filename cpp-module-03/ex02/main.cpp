#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ClapTrap    JoaquinJavier("Jokin");
    ScavTrap    ManuelFerran("Manu");
    FragTrap    LuisMiguel("Miguel");
    FragTrap    MariaLuisa("Luisa");

    std::cout << std::endl;
    JoaquinJavier.attack("Manu");
    ManuelFerran.takeDamage(0);
    ManuelFerran.guardGate();
    std::cout << "ScavTrap " << ManuelFerran.getName() << " is now very angry" << std::endl;
    LuisMiguel.highFivesGuys();
    MariaLuisa.highFivesGuys();
    std::cout << std::endl;
}
