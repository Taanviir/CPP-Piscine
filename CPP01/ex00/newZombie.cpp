#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* newZombie = new Zombie(name);
	if (!newZombie) {
		perror("Zombie allocation failed.");
		return NULL;
	}
	return newZombie;
}