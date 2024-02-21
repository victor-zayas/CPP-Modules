#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template	<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>() {};
		MutantStack(const MutantStack& to_copy): std::stack<T>(static_cast<std::stack<T> > (to_copy)) {};
		MutantStack& operator=(const MutantStack& to_asign) {static_cast<std::stack<T> > (this) = static_cast<std::stack<T> > (to_asign);};
		~MutantStack() {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin() { return std::stack<T>::c.begin();}
		iterator end() { return std::stack<T>::c.end();}
		const_iterator begin() const { return std::stack<T>::c.begin();}
		const_iterator end() const { return std::stack<T>::c.end();}
};

#endif
