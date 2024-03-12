#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stdexcept>
#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <cerrno>
#include <cstdlib>
#include <climits>
#include <algorithm>
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

    bool parseInput(char **args, int argc);

    // Sorter
    template<class Iterator>
    void insertSort(Iterator first, Iterator last) {
        for (Iterator i = first + 1; i != last; i++) {
            Iterator j = i;
            while (j != first && *j < *(j - 1)) {
                std::iter_swap(j, j - 1);
                --j;
            }
        }
    }

    template<class Container, class Iterator>
    void mergeInsertSort(Container &nbArray, Iterator first, Iterator last) {
        if (last - first <= 1) {
            if (*first > *last) {
                std::iter_swap(first, last);
            }
        } else if (last - first <= 16) {
            insertSort(first, last + 1);
        } else {
            Iterator middle = first + ((last - first) / 2);
            mergeInsertSort(nbArray, first, middle);
            mergeInsertSort(nbArray, middle + 1, last);
            my_InplaceMerge(first, middle + 1, last + 1);
        }
    }

    // Merge function
    template<class Iterator>
    void my_InplaceMerge(Iterator first, Iterator middle, Iterator last) {
        std::vector<int> temp(first, last);
        typename std::vector<int>::iterator left = temp.begin();
        typename std::vector<int>::iterator right = temp.begin() + (middle - first);
        typename std::vector<int>::iterator end = temp.end();

        while (left != temp.begin() + (middle - first) && right != end) {
            if (*left <= *right) {
                *first = *left;
                ++left;
            } else {
                *first = *right;
                ++right;
            }
            ++first;
        }
        while (left != temp.begin() + (middle - first)) {
            *first = *left;
            ++left;
            ++first;
        }
        while (right != end) {
            *first = *right;
            ++right;
            ++first;
        }
    }
};

#endif
