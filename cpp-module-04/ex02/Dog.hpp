# ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain   *_brain;

public:
    Dog();
    Dog(std::string name);
    Dog(const Dog &copy);
    Dog &operator=(const Dog &other);
    ~Dog();

    void    makeSound() const;
};

#endif
