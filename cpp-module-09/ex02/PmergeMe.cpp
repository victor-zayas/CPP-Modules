#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
: _deque(), _vector() {}

PmergeMe::PmergeMe(const PmergeMe &cpy)
: _deque(cpy._deque), _vector(cpy._vector) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    this->_deque = other._deque;
    this->_vector = other._vector;
    return  *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> &PmergeMe::getVector() {
    return this->_vector;
}

std::deque<int> &PmergeMe::getDeque() {
    return this->_deque;
}

bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
    }
    return true;
}


bool    PmergeMe::parseInput(char** args, int argc) {
    for (int i = 0; i < argc; i++) {
        if (std::strtol(args[i], NULL, 10) <= 0
            || std::strtol(args[i], NULL, 10) > INT_MAX) {
            throw std::invalid_argument("invalid argument");
        }
        for (size_t j = 0; args[i][j]; j++) {
            if (!std::isdigit(args[i][j])) {
                throw std::invalid_argument("invalid argument");
            }
        }
        this->_vector.push_back(std::strtol(args[i], NULL, 10));
    }

    if (isSorted(this->_vector)) {
        throw std::invalid_argument("arguments are already sorted");
    }

    for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++) {
        this->_deque.push_back(*it);
    }
    return 0;
}
