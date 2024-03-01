#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stdexcept>
#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
private:
    std::deque<int>     _deque;
    std::vector<int>    _vector;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &cpy);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    std::vector<int> &getVector();
    std::deque<int> &getDeque();

    bool    parseInput(char **args, int argc);

    //sorter
    template<class Iterator>
    void    insertSort(Iterator first, Iterator last) {
        for (Iterator i = first + 1; i != last; i++) {
            Iterator j = i;
            while (j != first && *j < *(j - 1)) {
                std::iter_swap(j, j - 1);
                --j;
            }
        }
    }

    template<class Container, class Iterator>
    void    mergeInsertSort(Container &nbArray, Iterator first, Iterator last) {
        if (last - first <= 1) {
            if (*first > *last) {
                std::iter_swap(first, last);
            }
        } else if (last - first <= 16) {
            insertSort(first, last + 1);
        } else {
                Iterator    middle = first + ((last - first) / 2);
                mergeInsertSort(nbArray, middle + 1, last);
                mergeInsertSort(nbArray, first, middle);
                std::inplace_merge(first, middle + 1, last + 1);
            }
    }
};

#endif
