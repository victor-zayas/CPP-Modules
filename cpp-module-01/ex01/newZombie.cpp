
#include"zombie.hpp"

Zombie	*Zombie::newZombie(std::string name) {
	Zombie *newZombie = new Zombie();
	newZombie->setName(name);
	return newZombie;
}

Zombie	*Zombie::zombieHorde(int n, std::string name) {
	// It must allocate N Zombie objects in a single allocation.
	// The function returns a pointer to the first zombie.
}