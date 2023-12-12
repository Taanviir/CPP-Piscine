#include <iostream>
#include <string>
#include <fstream>

#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define ORANGE "\e[1;33m"
#define WHITE "\e[0m"

static void replaceStringInFile(std::ofstream& outFile, std::string& line, const std::string& target, const std::string& replacement) {
	size_t startPos = 0;
	size_t foundPos;
	while ((foundPos = line.find(target, startPos)) != std::string::npos) {
		outFile << line.substr(startPos, foundPos - startPos) << replacement;
		startPos = foundPos + target.length();
	}
	outFile << line.substr(startPos) << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./replace_string <input file> <string1> <string2>" << std::endl;
		return 1;
	}

	std::string inputFile = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	std::ifstream inFile;
	inFile.open(inputFile.c_str());
	if (inFile.fail()) {
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}

	std::string outputFile = inputFile + ".replace";
	std::ofstream outFile(outputFile.c_str());
	if (outFile.fail()) {
		std::cout << "Error: could not create output file" << std::endl;
		inFile.close();
		return 1;
	}

	std::string line;
	while (true) {
		if (getline(inFile, line))
			replaceStringInFile(outFile, line, str1, str2);
		else if (inFile.eof())
			break;
		else {
			std::cout << "Error: could not read file" << std::endl;
			inFile.close();
			return 1;
		}
	}

	inFile.close();
	outFile.close();

	std::cout << "Successfully replaced " RED << str1 << WHITE " with " GREEN
		<< str2 << WHITE " in " ORANGE << outputFile << std::endl;
	return 0;
}