#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* d = new WrongCat();

    std::cout << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;
    i->makeSound(); //will output the Cat sound!
    j->makeSound(); //will output the Dog sound!
    meta->makeSound();
    std::cout << std::endl;

    d->makeSound(); //will output the WrongCat sound!
    wrong->makeSound();
    std::cout << std::endl;

    delete  i;
    delete  j;
    delete  meta;
    delete  d;
    delete  wrong;
}
