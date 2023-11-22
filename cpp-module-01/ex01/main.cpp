
#include"zombie.hpp"

int	main(void) {

	std::cout << "A very big explosion can been saw from afar" << std::endl;
	std::cout << "the whole world is mutating..." << std::endl;

    // pointer to newZombie
	Zombie *pepeZombie = newZombie("pepe");

	// randomChump
	randomChump("juan");

	std::cout << "OH NO! A ZOMBIE HORDE APPROACH" << std::endl;
	Zombie *horde = zombieHorde(5, "Mike");

	// use delete because newZombie is stored in heap
	delete pepeZombie;
	// use delete in each zombie of horde
	delete[] horde;
}
