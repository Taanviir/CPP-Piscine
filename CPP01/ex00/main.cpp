#include "Zombie.hpp"

int main(void) {
	std::cout << "<----------- STACK ZOMBIES ---------->" << std::endl;
	Zombie stackZombie1("stackZombie1");
	Zombie stackZombie2;
	stackZombie1.announce();
	stackZombie2.announce();
	randomChump("randomChump");
	
	std::cout << std::endl;

	std::cout << "<----------- HEAP ZOMBIES ---------->" << std::endl;
	Zombie* heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	return 0;
}