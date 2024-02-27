#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _database(), _input_file() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	this->_database = cpy._database;
	this->max_year = cpy.max_year;
	this->max_year = cpy.min_year;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	this->_database = other._database;
	this->max_year = other.max_year;
	this->max_year = other.min_year;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::CreateDatabase(const char *database_name) {
	std::ifstream	database_file(database_name);

	if (!database_file.is_open()) {
		throw	std::invalid_argument("program needs a data.csv");
	}

	std::string	line;
	std::string	date;
	double value;

	std::getline(database_file, line);
	while (std::getline(database_file, date, ',')) {
		std::getline(database_file, line);
		value = std::strtod(line.c_str(), 0);
		this->_database.insert(std::make_pair(date, value));
	}
	this->min_year = std::strtol(_database.begin()->first.c_str(), NULL, 10);
	this->max_year = std::strtol((--_database.end())->first.c_str(), NULL, 10);
}

const std::ifstream &BitcoinExchange::GetInputFile() const {
	return this->_input_file;
}

const std::map<std::string, float> &BitcoinExchange::GetDatabase() const {
	return this->_database;
}
