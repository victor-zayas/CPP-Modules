/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:48:12 by abasante          #+#    #+#             */
/*   Updated: 2024/04/23 18:09:54 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Minimo y maximo dos argumentos" << std::endl;
        return (1);
    }
    RPN rpn(av[1]);
    rpn.reversePolishNotation();
    return (0);
}
