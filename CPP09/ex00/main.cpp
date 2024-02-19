#include "BitcoinExchange.hpp"
#include <sys/stat.h>

static bool validateDate(const std::string& date) {
    // Checking the date format
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7)
            continue; // Skipping '-'
        if (!isdigit(date[i]))
            return false;
    }

    // Checking the date values
    std::istringstream istream(date);
    int year, month, day;
    char dash;
    if (!(istream >> year >> dash >> month >> dash >> day))
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (year < 2000)
        return false;

    // Checking for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    // Checking for February
    if (month == 2) {
        // Check for leap year
        bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (leapYear && day > 29)
            return false; // February has 29 days in a leap year
        else if (!leapYear && day > 28)
            return false; // February has 28 days in a non-leap year
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./btc [input file]" << std::endl;
        return 1;
    }

    // Checking if the input file exists and is not a directory
    struct stat fileInfo;
    stat(argv[1], &fileInfo);
    if (S_ISDIR(fileInfo.st_mode)) {
        std::cout << "Error: " << argv[1] << " is a directory" << std::endl;
        return 1;
    }

    // Checking if the input file cannot be opened or is empty
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cout << "Error: could not open " << argv[1] << std::endl;
        return 1;
    }
    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: " << argv[1] << " is empty" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    // Reading the input file
    std::string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line.compare("date | value") == 0)
            continue;

        size_t pos = line.find('|');
        // check for delimiter
        if (pos == std::string::npos) {
            std::cout << ERROR_MISSING_DEL << " => " << line << std::endl;
            continue;
        }
        // check for date and validate it
        std::string date = line.substr(0, pos - 1);
        if (!validateDate(date)) {
            std::cout << ERROR_BAD_DATE << " => " << date << std::endl;
            continue;
        }
        // check for value and validate it
        double value = strtod(line.substr(pos + 2).c_str(), NULL);
        if (value < 0) {
            std::cout << ERROR_NEGATIVE << std::endl;
            continue;
        } else if (value > 1000) {
            std::cout << ERROR_LARGE << std::endl;
            continue;
        } else if (value == 0) {
            std::cout << ERROR_MISSING_VALUE << std::endl;
            continue;
        }

        double newAmount = exchange.convertAmount(date, value);
        std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << newAmount << std::endl;
    }

    inputFile.close();
    return 0;
}
