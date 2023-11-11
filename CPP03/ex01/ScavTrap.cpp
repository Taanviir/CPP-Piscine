#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardMode = false;
	std::cout << "Default constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy) {
	*this = copy;
	std::cout << "Copy constructor called for ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardMode = false;
	std::cout << "Constructor called for ScavTrap " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor called for ScavTrap " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	if (this == &copy) return *this;

	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	this->_guardMode = copy._guardMode;
	std::cout << "Copy operator called for ScavTrap " << this->_name << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " cannot attack due to insufficient energy points. 😴" << std::endl;
		return;
	} else if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " has fallen. ☠️" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! ⚔️" << std::endl;
	_energyPoints--;
}
void ScavTrap::guardGate(void) {
	if (_guardMode == true) {
		std::cout << "ScavTrap " << _name << " has already been guarding the gate! 😤" << std::endl;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode 💂" << std::endl;
	_guardMode = true;
}