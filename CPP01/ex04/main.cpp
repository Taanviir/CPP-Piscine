#include <iostream>
#include <string>
#include <fstream>

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
		std::cout << "Usage: ./replace_string <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inFile;
	inFile.open(argv[1]);
	if (inFile.fail()) {
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}

	std::string outputFilename = filename + ".replace";
	std::ofstream outFile(outputFilename.c_str());
	if (outFile.fail()) {
		std::cout << "Error: could not create output file" << std::endl;
		inFile.close();
		return 1;
	}

	std::string line;
	while (true) {
		if (getline(inFile, line))
			replaceStringInFile(outFile, line, s1, s2);
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

	std::cout << "Successfully replaced \e[1;31m" << s1 << "\e[0m with \e[1;32m" << s2 << "\e[0m in \e[1;33m" << argv[1] << std::endl;
	return 0;
}