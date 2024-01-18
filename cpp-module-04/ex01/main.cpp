#include "Cat.hpp"
#include "Dog.hpp"

void    subject(void) {
    std::cout << std::endl;
    std::cout << "Subject" << std::endl;
    std::cout << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    delete j;//should not create a leak
    delete i;
    std::cout << std::endl;
}

void	fillloop(Animal	*Array[4])
{
	size_t i = 0;

	while (i < 4 / 2)
	{
		Array[i] = new Dog;
		i++;
	}
	while (i < 4)
	{
		Array[i] = new Cat;
		i++;
	}
}

void	deleteloop(Animal	*Array[4])
{
	size_t i = 0;

	while (i < 4)
	{
		delete(Array[i]);
		i++;
	}
}

void	makesoundsloop(Animal	*Array[4])
{
	size_t i = 0;

	while (i < 4)
	{
		Array[i]->makeSound();
		i++;
	}
}

void	mandatory()
{
    
	std::cout << "\nMandatory" << std::endl;
    std::cout << std::endl;

	Animal	*Array[4];

	fillloop(Array);
    std::cout << std::endl;
	makesoundsloop(Array);
    std::cout << std::endl;
	deleteloop(Array);
    std::cout << std::endl;
}

int main()
{
    subject();
    mandatory();
	std::cout << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
	basic.displayIdea(5);
	std::cout << std::endl;
}
