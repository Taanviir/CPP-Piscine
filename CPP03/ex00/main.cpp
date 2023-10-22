#include "ClapTrap.hpp"

int main(void) {

	// Instantiating ClapTrap objects
	ClapTrap machine1("Jack");
	ClapTrap machine2("Mac");

	machine1.attack("f");
	machine2.takeDamage(0);
	machine2.beRepaired(0);

	return 0;
}