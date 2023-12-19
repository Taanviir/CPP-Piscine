#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	// Instantiating objects
	ClapTrap machine1("Jack");
	ScavTrap machine2("Mac");

	ClapTrap* pointerMachine = &machine2;
	pointerMachine->beRepaired(0);
	machine2.attack("f");
	machine1.takeDamage(0);
	machine2.beRepaired(0);
	machine2.guardGate();

	return 0;
}