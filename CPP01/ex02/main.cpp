#include <string>
#include <iostream>

int main(void) {
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringVAR;
	std::string& stringREF = stringVAR;

	std::cout << "Memory address in:" << std::endl
	<< "stringVAR - " << &stringVAR << std::endl
	<< "stringPTR - " << stringPTR << std::endl
	<< "stringREF - " << &stringREF << std::endl << std::endl;

	std::cout << "Value held in:" << std::endl
	<< "stringVAR - " << stringVAR << std::endl
	<< "stringPTR - " << *stringPTR << std::endl
	<< "stringREF - " << stringREF << std::endl;

	return 0;
}