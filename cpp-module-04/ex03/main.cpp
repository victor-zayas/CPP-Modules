#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	std::cout << std::endl;
	IMateriaSource *src = new MateriaSource();
	ICharacter *bob = new Character("bob");
	ICharacter *me = new Character("me");

	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << std::endl;
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
}
