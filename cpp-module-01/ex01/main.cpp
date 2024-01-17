
#include "Zombie.hpp"

int	main(void) {

	std::cout << "A very big explosion can been saw from afar..." << std::endl;
	std::cout << "The whole world is mutating..." << std::endl;

    // pointer to newZombie
	Zombie *pepeZombie = newZombie("pepe");

	// randomChump
	randomChump("juan");

	std::cout << "OH NO! A ZOMBIE HORDE APPROACH" << std::endl;
	Zombie *horde = zombieHorde(5, "The Mikes");

	// use delete because newZombie is stored in heap
	delete pepeZombie;
	// use delete in each zombie of horde
	delete[] horde;
}
