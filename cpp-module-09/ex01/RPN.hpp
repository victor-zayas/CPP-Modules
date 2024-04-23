/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:48:26 by abasante          #+#    #+#             */
/*   Updated: 2024/04/23 18:10:44 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class RPN {
private:
    std::stack<int> _stack;
    std::string input;

public:
    RPN();
    RPN(std::string input);
    RPN(const RPN &copy);
    RPN &operator=(const RPN &other);
    ~RPN();

    void reversePolishNotation();
};

#endif