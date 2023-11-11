#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombies = new Zombie[N];
	if (!zombies) {
		perror("Zombie allocation failed.");
		return NULL;
	}
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return zombies;
}