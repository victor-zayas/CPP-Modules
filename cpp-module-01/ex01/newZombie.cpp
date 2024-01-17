
#include "Zombie.hpp"

// Create & return a pointer to new zombie and save it on heap
Zombie	*newZombie(std::string name) {
	Zombie *newZombie = new Zombie();
	newZombie->setName(name);
	return newZombie;
}
