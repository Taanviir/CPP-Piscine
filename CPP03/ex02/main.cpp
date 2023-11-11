#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

	// Instantiating objects
	ClapTrap machine1("Jack");
	ScavTrap machine2("Mac");
	FragTrap machine3("Rex");

	machine3.highFivesGuys();

	return 0;
}