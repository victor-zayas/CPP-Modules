/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:48:21 by abasante          #+#    #+#             */
/*   Updated: 2024/04/23 18:12:57 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : input("") {}

RPN::RPN(std::string input) : input(input) {}


RPN::RPN(const RPN &copy){
    *this = copy;
}

RPN& RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack;
        this->input = other.input;
    }
    return (*this);
}

RPN::~RPN() {}

void	RPN::reversePolishNotation() {
	if (this->input.empty())
		return ;
	std::istringstream string_stream(input);
	std::string input_str;
	while (string_stream >> input_str) {
		if (input_str == "+" || input_str == "-" || input_str == "*" || input_str == "/" || input_str == "%") {
			if (_stack.size() < 2) {
				std::cout << "Error: Not enough values" << std::endl;
				return ;
			}
			double a = _stack.top();
			_stack.pop();	
			double b = _stack.top();
			_stack.pop();
			if (input_str == "+")
				_stack.push(b + a);
			else if (input_str == "-")
				_stack.push(b - a);
			else if (input_str == "*")
				_stack.push(b * a);
			else if (input_str == "/" && b != 0)
				_stack.push(b / a);
			else if (input_str == "/" && b == 0) {
				std::cout << "Error: can't divide by zero" << std::endl;
				return ;
			}
		}
		else if (std::isdigit(input_str[0])) {
			double number;
			if (atof(input_str.c_str()) < 0 || atof(input_str.c_str()) > 9) {
				std::cout << "Error: Invalid value" << std::endl;
				return ;
			}
			number = atof(input_str.c_str());
			_stack.push(number);
		}
		else {
			std::cout << "Error: Invalid value" << std::endl;
			return ;
		}
	}
	if (_stack.size() > 1) {
		std::cout << "Error: Too many values" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}
