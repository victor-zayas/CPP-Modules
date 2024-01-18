#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {
private:
	std::string _type;

public:
	Ice();
	Ice(std::string type);
	Ice(const Ice &copy);
	Ice &operator=(const Ice &other);
	~Ice();

	std::string	getType();

	void	use(ICharacter &target);
	AMateria	*clone() const;
};

#endif
