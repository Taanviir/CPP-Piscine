#include "ClapTrap.hpp"

int main(void) {

	// Instantiating ClapTrap objects
	ClapTrap machine1("Jack");
	ClapTrap machine2("Mac");
	ClapTrap machine3(NULL);

	machine1.attack("f");
	machine2.takeDamage(0);
	machine2.beRepaired(0);
	machine3.attack(NULL);

	return 0;
}