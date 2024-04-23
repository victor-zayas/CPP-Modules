/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:46:32 by abasante          #+#    #+#             */
/*   Updated: 2024/04/23 18:04:00 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    getCsv("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
    {
        this->_data = other._data;
        this->_rate = other._rate;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::getCsv(const std::string &database) {
    std::ifstream input(database.c_str());
    if (!input.is_open()) {
        std::cout << "Can't open the file" << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(input, line)) {
        size_t pos = line.find(",");
        if (pos == line.npos) {
            std::cout << "Wrong format on data.csv" << std::endl;
            return ;
        }
        std::string date = line.substr(0, line.find(","));
        std::string rate = line.substr(line.find(",") + 1);
		this->_data[date] = std::atof(rate.c_str());
    }
    input.close();
}

std::string BitcoinExchange::getDate(std::string date) {
    std::map<std::string, float>::iterator it = this->_data.lower_bound(date);
	if (it == this->_data.end())
		return _data.rbegin()->first;
	if (it->first == date)
		return date;
	if (it == this->_data.begin())
		return it->first;
	else
		it--;
	return it->first;
}

int BitcoinExchange::validDate(std::string date) {
    if (date.find('-') == date.npos)
        return (1);
    if (date.length() != 11 || date[4] != '-' || date[7] != '-')
        return (1);
    if (std::atoi(date.substr(0, 4).c_str()) < 2009 || std::atoi(date.substr(0, 4).c_str()) > 2022)
        return (1);
    if (std::atoi(date.substr(5, 2).c_str()) < 1 || std::atoi(date.substr(5, 2).c_str()) > 12)
        return (1);
    if (std::atoi(date.substr(8, 2).c_str()) < 1 || std::atoi(date.substr(8, 2).c_str()) > 31)
		return (1);
    if (std::atoi(date.substr(5, 2).c_str()) == 2 && std::atoi(date.substr(8, 2).c_str()) > 29)
		return (1);
    this->_date = getDate(date);
    return (0);
}

int BitcoinExchange::validRate(std::string rate) {
    if (rate.size() == 0)
        return (1);
    if (rate.find(".") == rate.npos) {
		if (std::atoi(rate.c_str()) < 0 || std::atoi(rate.c_str()) > 1000)
			return (1);
	}
	else {
		if (std::atof(rate.c_str()) < 0 || std::atof(rate.c_str()) > 1000)
			return (1);
	}
    this->_rate = std::atof(rate.c_str());
    return (0);
}

void BitcoinExchange::parse_line(std::string date, std::string rate) {
    if (validDate(date) == 1) {
        std::cout << "Wrong date" << std::endl;
        return ;
    }
    else if (validRate(rate) == 1) {
        std::cout << "wrong rate" << std::endl;
        return ;
    }
    std::cout << date << " => " << this->_rate << " = " << this->_rate * _data[this->_date] << std::endl;
}

void BitcoinExchange::parse_input(std::string file) {
    std::ifstream input(file.c_str());
    if (!input.is_open()) {
        std::cout << "Can't open the file" << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(input, line)) {
        size_t pos = line.find('|');
        if (pos == line.npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::string date = line.substr(0, line.find('|'));
        std::string rate = line.substr(line.find('|') + 1);
        this->parse_line(date, rate);
    }
}
