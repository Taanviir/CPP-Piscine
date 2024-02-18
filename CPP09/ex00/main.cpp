#include "BitcoinExchange.hpp"
#include <sys/stat.h>

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

    // Reading the input file
    std::string line;
    

    BitcoinExchange btc;

    return 0;
}
