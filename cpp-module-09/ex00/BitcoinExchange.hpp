/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:46:34 by abasante          #+#    #+#             */
/*   Updated: 2024/04/23 18:04:12 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> _data;
    std::string _date;
    double _rate;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void getCsv(const std::string &database);
    std::string getDate(std::string date);

    void parse_line(std::string date, std::string rate);
    void parse_input(std::string file);

    int  validDate(std::string date);
    int  validRate(std::string rate);
};

#endif