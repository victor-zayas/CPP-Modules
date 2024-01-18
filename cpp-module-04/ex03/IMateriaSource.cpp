#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(std::string type): _type(type) {
	for (int i=0; i < 4; i++) {
		this->_slot[i] = "unknown";
	}
	std::cout << "IMateriaSource constructor called" << std::endl;	
}

void	IMateriaSource::learnMateria(AMateria *materia) {

}


AMateria	*IMateriaSource::createMateria(std::string const &type) {
	// return new IMateriaSource(type);
}
