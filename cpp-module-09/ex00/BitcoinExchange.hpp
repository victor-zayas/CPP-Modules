#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float>	_database;
	std::ifstream					_input_file;

public:
	unsigned short 				min_year;
	unsigned short 				max_year;
	static const unsigned short	date_width = 11;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

    const std::ifstream				&GetInputFile() const;
	const std::map<std::string, float> &GetDatabase() const;

	void	CreateDatabase(const char *database_name);
};

#endif
