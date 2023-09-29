#include "Harl.hpp"

static int getLevelOfProblem(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	int	level = getLevelOfProblem(argv[1]);
	switch (level) {
		case 0:
			harl.complain("DEBUG");
			// intentional fallthrough
		case 1:
			harl.complain("INFO");
			// intentional fallthrough
		case 2:
			harl.complain("WARNING");
			// intentional fallthrough
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignifcant problems ]" << std::endl;
			return 1;
	}

	return 0;
}