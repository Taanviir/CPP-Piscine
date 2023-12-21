#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	// Instantiating objects
	// ClapTrap machine1("Jack");
	// ScavTrap machine2("Mac");
	// FragTrap machine3("Rex");
	DiamondTrap machine4(NULL);

	machine4.whoAmI();

	return 0;
}