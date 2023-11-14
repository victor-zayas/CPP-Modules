
#include"zombie.hpp"

int	main(void) {
	Zombie	zombie;

	std::cout << "A very big explosion can been saw from afar" << std::endl;
	std::cout << "the whole world is mutating..." << std::endl;
	
	// puntero a newZombie
	// Zombie *pepeZombie = zombie.newZombie("pepe");

	// newZombie
	zombie.newZombie("pepe");
	// randomChump
	zombie.randomChump("juan");

	// use delete if you create newZombie in heap
	// delete pepeZombie;
}
