#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;
    public:
        BitcoinExchange(std::string file);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        std::map<std::string, double> getData() const;
        void print() const;
        int checkDate(std::string date, int mod) const;
        double exchange(std::string date, double value) const;
        std::string finDate(const std::string &date) const;
};

bool isNum(const std::string &str, int mod);
int checkNum(double nb);
double stringToDouble(const std::string &str);

#endif
