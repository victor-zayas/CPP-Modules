#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
private:
    std::vector<int> _vector;
    unsigned int _size;
public:
    Span();
    Span(unsigned int val);
    Span(const Span &copy);
    const Span	&operator=(const Span &other);
    ~Span();

    void    addNumber(unsigned int nb);
    int			shortestSpan(void) const;
	int			longestSpan(void) const;
};

#endif