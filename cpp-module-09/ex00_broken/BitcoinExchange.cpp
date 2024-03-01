#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file) {
    std::ifstream fd(file.c_str());

    if (!fd.good())
        std::cerr << "Error: invalid .csv file" << std::endl;
    std::string line;
    while (getline(fd, line)) {
        std::string date = line.substr(0, line.find('|'));
        std::string value = line.substr(line.find(',') + 1);
        if (date == "date")
            continue ;
        if (!checkDate(date, 0) || !isNum(value, 0)) {
            fd.close();
            this->_data.clear();
            std::cout << "Error: bad .csv file" << std::endl;
            exit(0);
            // throw std::invalid_argument("Error: bad .csv file");
        }
        double amount = stringToDouble(value);
        this->_data[date] = amount;
    }
    if (this->_data.size() == 0) {
        fd.close();
        this->_data.clear();
        std::cout << "Error: empty .csv file" << std::endl;
        exit(0);
        // throw std::invalid_argument("Error: empty .csv file");
    }
    fd.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->_data = other.getData();
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    this->_data.clear();
}

std::map<std::string, double> BitcoinExchange::getData() const {
    return this->_data;
}

void BitcoinExchange::print() const {
    for (std::map<std::string, double>::const_iterator it = this->_data.begin(); it != this->_data.end(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}

int BitcoinExchange::checkDate(std::string date, int mod) const {
    std::istringstream iss(date);
    std::string year, month, day;
    double num;
    
    if (mod == 1 && date < this->_data.begin()->first)
        return 0;
    std::getline(iss, year, '-');
    if (year.length() != 4 || !isNum(year, 1))
        return 0;
    num = stringToDouble(year);
    if (num < 2009)
        return 0;
    
    std::getline(iss, month, '-');
    if (year.length() != 2 || !isNum(month, 1))
        return 0;
    num = stringToDouble(month);
    if (num < 1 || num > 12)
        return 0;

    std::getline(iss, day, '-');
    if (year.length() != 2 || !isNum(day, 1))
        return 0;
    num = stringToDouble(day);
    if (num < 1 || num > 31)
        return 0;

    return 1;
}

double BitcoinExchange::exchange(std::string date, double value) const {
    std::string i;

    i = finDate(date);
    return this->_data.find(i)->second * value;
}

std::string BitcoinExchange::finDate(const std::string &date) const {
    std::map<std::string, double>::const_iterator begin = this->_data.begin();
    std::map<std::string, double>::const_iterator end = this->_data.end();
    std::string res = begin->first;

    while (begin != end) {
        if (begin->first > date)
            return res;
        res = begin->first;
        begin++;
    }
    return res;
}

bool isNum(const std::string &str, int mod) {
    int count = 0;

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (mod == 0) {
            if (*it  == '.')
                count++;
            if ((!isdigit(*it) && *it != '.') || count == 1)
                return false;
        }
        if (mod == 1 && !isdigit(*it))
            return false;
    }
    return true;
}

int checkNum(double nb) {
    if (nb < 0) {
        std::cerr << "Error: not a positive number" << std::endl;
        return 0;
    }
    if (nb > 1000) {
        std::cerr << "Error: number is too large" << std::endl;
        return 0;
    }
    return 1;
}

double stringToDouble(const std::string &str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}
