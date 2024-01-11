#include "ClapTrap.hpp"

int main(void) {
    ClapTrap    JoaquinJavier("Jokin");
    ClapTrap    LuisMiguel("Luis");
    ClapTrap    Nameless = ClapTrap();
    ClapTrap    Copy = ClapTrap(Nameless);

    std::cout << std::endl;
    JoaquinJavier.attack("Luis");
    LuisMiguel.takeDamage(1);
    LuisMiguel.beRepaired(10);
    std::cout << std::endl;

    std::cout << "ClapTrap " << JoaquinJavier.getName() << " is hit by P.E.M. grenade" << std::endl;
    JoaquinJavier.takeDamage(5);
    JoaquinJavier.setEnergyPoints(0);
    LuisMiguel.attack("Jokin");
    JoaquinJavier.takeDamage(0);
    JoaquinJavier.attack("Luis");
    JoaquinJavier.beRepaired(10);

    std::cout << std::endl;
    Nameless.attack("Copy");
    Copy.takeDamage(0);
    Copy.beRepaired((10));
    std::cout << std::endl;
}
