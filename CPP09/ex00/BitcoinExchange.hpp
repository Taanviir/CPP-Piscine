#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <vector>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <sstream>

// Error messages
#define ERROR_DATE_FORMAT "Error: bad input"
#define ERROR_MISSING_VALUE "Error: value is missing."
#define ERROR_LARGE "Error: value is too large."
#define ERROR_NEGATIVE "Error: value is not positive."

#define DATA_FILE "./data.csv"

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();

    double convertAmount(const std::string& date, double amount);

private:
    std::map<std::string, double> _exchangeRates;

    BitcoinExchange(BitcoinExchange const& copy);
    BitcoinExchange &operator=(BitcoinExchange const& copy);
};

#endif // BITCOINEXCHANGE_HPP
