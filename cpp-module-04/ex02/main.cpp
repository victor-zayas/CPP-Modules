#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
 	std::cout << std::endl;
    std::cout << "<-----TEST----->" << std::endl;
    std::cout << std::endl;
    
	const Animal	*Tom = new Dog();
    const Animal	*Spike = new Cat();
	// const Animal	*Unkwon = new Animal();
    std::cout << std::endl;
    
	Tom->makeSound();
	Spike->makeSound();
	// Unkwon->makeSound();
    std::cout << std::endl;

	delete Tom;
    delete Spike;
    std::cout << std::endl;
}
