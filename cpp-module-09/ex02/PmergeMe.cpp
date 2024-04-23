/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:48:41 by abasante          #+#    #+#             */
/*   Updated: 2024/04/23 18:36:31 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::dequeBefore() {
    std::deque<int>::iterator it = _deque.begin();
    std::deque<int>::iterator ite = _deque.end();

    std::cout << "Before: ";
    while (it != ite) {
        std::cout << *it << " ";
        it++;
    }
}

void PmergeMe::vectorBefore() {
    std::vector<int>::iterator it = _vector.begin();
    std::vector<int>::iterator ite = _vector.end();

    std::cout << "Before: ";
    while (it != ite) {
        std::cout << *it << " ";
        it++;
    }
}

void PmergeMe::vectorAfter() {
    std::vector<int>::iterator it = _vector.begin();
    std::vector<int>::iterator ite = _vector.end();

    std::cout << "After: ";
    while (it != ite) {
        std::cout << *it << " ";
        it++;
    }
}

void PmergeMe::getInput(char **argv) {
    for (size_t i = 1; argv[i]; i++) {
        std::string line = argv[i];
        if (line.empty())
            return ;
        size_t j = 0;
        for (; j < line.size(); j++) {
            if (!isdigit(argv[i][j])) {
                std::cout << "Error: invalid input" << std::endl;
                exit(1);
            }
        }
        double number = static_cast<double>(atof(argv[i]));
        if (number < 0 || number > 2147483647) {
            std::cout << "Error: value not in range" << std::endl;
            exit(1);
        }
        this->_vector.push_back(atoi(argv[i]));
        this->_deque.push_back(atoi(argv[i]));
    }
}

void	PmergeMe::insertionSort(std::deque<int> &deque) {
	for (size_t i = 1; i < deque.size(); i++) {
		int key = deque[i];
		int j = i - 1;
		while (j >= 0 && deque[j] > key) {
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = key;
	}
}

void PmergeMe::mergeInsertionSort(std::deque<int> &deque) {
	std::deque<int> deque1;
	std::deque<int> deque2;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (size_t i = 0; i < deque.size(); i++) {
		if (i % 2 == 0)
			deque1.push_back(deque[i]);
		else
			deque2.push_back(deque[i]);
    }
	if (deque1.size() > 1)
        mergeInsertionSort(deque1);
    if (deque2.size() > 1)
        mergeInsertionSort(deque2);
    while (i < deque1.size() && j < deque2.size()) {
        if (deque1[i] < deque2[j])
            deque[k++] = deque1[i++];
        else
            deque[k++] = deque2[j++];
    }
    while (i < deque1.size())
        deque[k++] = deque1[i++];
    while (j < deque2.size())
        deque[k++] = deque2[j++];
    insertionSort(deque);
}

void	PmergeMe::insertionSort(std::vector<int> &vector) {
	for (size_t i = 1; i < vector.size(); i++) {
		int key = vector[i];
		int j = i - 1;
		while (j >= 0 && vector[j] > key) {
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = key;
	}
}

void PmergeMe::mergeInsertionSort(std::vector<int> &vector) {
    std::vector<int> vector1;
	std::vector<int> vector2;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (size_t i = 0; i < vector.size(); i++) {
		if (i % 2 == 0)
			vector1.push_back(vector[i]);
		else
			vector2.push_back(vector[i]);
    }
	if (vector1.size() > 1)
        mergeInsertionSort(vector1);
    if (vector2.size() > 1)
        mergeInsertionSort(vector2);
    while (i < vector1.size() && j < vector2.size()) {
        if (vector1[i] < vector2[j])
            vector[k++] = vector1[i++];
        else
            vector[k++] = vector2[j++];
    }
    while (i < vector1.size())
        vector[k++] = vector1[i++];
    while (j < vector2.size())
        vector[k++] = vector2[j++];
    insertionSort(vector);
}

void PmergeMe::pMerge(char **argv) {
	struct timeval start;
    struct timeval end;
    
    this->getInput(argv);
    if (this->_vector.size() < 2) {
		std::cout << "Error: invalid input" << std::endl;
		exit(1);
	}
    
    this->vectorBefore();
    std::cout << std::endl;
	gettimeofday(&start, NULL);
	this->mergeInsertionSort(this->_vector);
	gettimeofday(&end, NULL);
    this->vectorAfter();
    std::cout << std::endl;

	long long time = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "Time to process a range of "<< _vector.size() << " elements with std::vector : " << time << "us" << std::endl;
	gettimeofday(&start, NULL);
	this->mergeInsertionSort(this->_deque);
	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "Time to process a range of "<< _deque.size() << " elements with std::deque : " << time << "us" << std::endl;
}
