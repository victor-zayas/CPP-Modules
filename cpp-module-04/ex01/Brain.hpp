#ifndef CPP_MODULES_BRAIN_H
#define CPP_MODULES_BRAIN_H

#include <iostream>
#include <sstream>

class   Brain {
private:
    std::string _ideas[100];

public:

    Brain();
    Brain(const Brain &copy);
    Brain &operator=(const Brain &other);
    ~Brain();

    void    setIdeas(int i, std::string idea);
    std::string getIdeas(int i);
};

#endif
