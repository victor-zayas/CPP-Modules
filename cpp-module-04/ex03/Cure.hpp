#ifndef Cure_HPP
# define Cure_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {
private:
	std::string _type;

public:
	Cure();
	Cure(std::string type);
	Cure(const Cure &copy);
	Cure &operator=(const Cure &other);
	~Cure();

	std::string	getType();

	void	use(ICharacter &target);
};

#endif
