
#include"zombie.hpp"

Zombie  *zombieHorde(int n, std::string name) {
    Zombie *zombieHorde = new Zombie[n]; // allocate N zombies

    for (int i = 0; i < n; ++i) {
        zombieHorde[i].setName(name);
        zombieHorde[i].announce();
    }
    return zombieHorde;
}
