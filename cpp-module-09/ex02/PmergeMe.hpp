/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:48:46 by abasante          #+#    #+#             */
/*   Updated: 2024/04/23 18:36:41 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int>  _deque;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void getInput(char **av);
    void vectorBefore();
    void vectorAfter();
    void dequeBefore();

    void mergeInsertionSort(std::vector<int> &vector);
    void insertionSort(std::vector<int> &vector);

    void mergeInsertionSort(std::deque<int> &deque);
    void insertionSort(std::deque<int> &deque);
    
    void pMerge(char **argv);
};

#endif