#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <vector>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <iomanip>

// Error messages
# define ERROR_BAD_DATE "Error: bad input"
# define ERROR_MISSING_DATA "Error: missing date."
# define ERROR_MISSING_VALUE "Error: missing value."
# define ERROR_MISSING_DEL "Error: missing delimiter."
# define ERROR_LARGE "Error: value is too large."
# define ERROR_NEGATIVE "Error: not a positive number."

# define DATA_FILE "./data.csv"

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
