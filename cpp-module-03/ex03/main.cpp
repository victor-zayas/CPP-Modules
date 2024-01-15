#include "DiamondTrap.hpp"

int main(void) {
    ClapTrap    JoaquinJavier("Jokin");
    ScavTrap    ManuelFerran("Manu");
    FragTrap    LuisMiguel("Miguel");
    FragTrap    MariaLuisa("Luisa");
    DiamondTrap Amalgame("Amalgame");

    std::cout << std::endl;
    JoaquinJavier.attack("Manu");
    ManuelFerran.takeDamage(0);
    ManuelFerran.guardGate();
    std::cout << "ScavTrap " << ManuelFerran.getName() << " is now very angry" << std::endl;
    LuisMiguel.highFivesGuys();
    MariaLuisa.highFivesGuys();
    std::cout << std::endl;
    std::cout << "everyone turn around and see " << Amalgame.getName() << " in a corner" << std::endl;
    Amalgame.whoAmI();
    std::cout << "Amalgame has an identity problem" << std::endl; 
    Amalgame.guardGate();
    std::cout << "Amalgame is lost on his own thoughts" << std::endl;
    std::cout << std::endl;
}
