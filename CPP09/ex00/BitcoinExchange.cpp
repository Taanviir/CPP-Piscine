#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    // Reading the exchange rates from the data.csv file
    std::ifstream dataFile(DATA_FILE);
    if (!dataFile.is_open())
        throw std::runtime_error("Error: could not open data.csv file");

    std::string line;
    while (getline(dataFile, line)) {
        if (line.empty() || line.compare("date,exchange_rate") == 0)
            continue;
        
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            throw std::runtime_error("Error: bad data format");
        
        std::string date = line.substr(0, pos);
        double rate = strtod(line.substr(pos + 1).c_str(), NULL);
        std::pair<std::string, double> entry(date, rate);
        _exchangeRates.insert(entry);
    }
    dataFile.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy) {
    (void) copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& copy) {
    (void) copy;
    return *this;
}

double BitcoinExchange::convertAmount(const std::string& date, double amount) {
    double closestRate = 0;
    for (std::map<std::string, double>::iterator mapItr = _exchangeRates.begin();
        mapItr != _exchangeRates.end(); mapItr++)
    {
        if ((*mapItr).first.compare(date) <= 0)
            closestRate = (*mapItr).second;
        else
            break;
    }
    return closestRate * amount;
}
