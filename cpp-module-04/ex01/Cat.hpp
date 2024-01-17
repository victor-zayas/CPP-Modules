# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain   *_brain;

public:
    Cat();
    Cat(std::string name);
    Cat(const Cat &copy);
    Cat &operator=(const Cat &other);
    ~Cat();

    void    makeSound() const;
};

#endif
