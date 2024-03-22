#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

#include <algorithm>
#include <iostream>
#include <climits>

#include <stdexcept>
#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <cerrno>

class PmergeMe {
private:
    std::deque<int>     _deque;
    std::vector<int>    _vector;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool    parseInput(char **args, int argc);

    std::vector<int>    &getVector();
    std::deque<int>     &getDeque();

    //sorter
    template<class Iterator>
    void    insertSort(Iterator start, Iterator end) {
        for (Iterator i = start + 1; i != end; i++) {
            Iterator j = i;
            while (j != start && *j < *(j - 1)) {
                std::iter_swap(j, j - 1);
                --j;
            }
        }
    }

    template<class Container, class Iterator>
    void    mergeInsertSort(Container &Array, Iterator start, Iterator end) {
        if (end - start <= 1) {
            if (*start > *end) {
                std::iter_swap(start, end);
            }
        }
        else if (end - start <= 16) {
            insertSort(start, end + 1);
        }
        else {
            Iterator    middle = start + ((end - start) / 2);
            mergeInsertSort(Array, middle + 1, end);
            mergeInsertSort(Array, start, middle);
            std::inplace_merge(start, middle + 1, end + 1);
        }
    }
};

#endif