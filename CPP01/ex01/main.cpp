#include "Zombie.hpp"

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Usage: ./zombieHorde <number of zombies> <name>" << std::endl;
		return 1;
	}
	int N = atoi(argv[1]);
	if (N <= 0) {
		std::cout << "Invalid number of zombies" << std::endl;
		return 1;
	}
	Zombie* zombies = zombieHorde(N, argv[2]);
	if (!zombies) {
		std::cout << "Failed to allocate memory for zombies" << std::endl;
		return 1;
	}
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	std::cout << "All zombies have been erradicated" << std::endl;
	return 0;
}