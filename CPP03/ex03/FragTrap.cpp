#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default constructor called for FragTrap" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor called for FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy) {
	std::cout << "Copy constructor called for FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(std::string* name): ClapTrap(name) {
	if (name == NULL || (*name).empty()) {
		std::cout << "Invalid name entered for FragTrap, name set to \"Unknown\". ❌" << std::endl;
	}
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Constructor called for FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	if (name.empty()) {
		std::cout << "Invalid name entered for FragTrap, name set to \"Unknown\". ❌" << std::endl;
	}
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Constructor called for FragTrap " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	std::cout << "Copy operator called for FragTrap " << this->_name << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Hello, I am FragTrap " << _name << ", lets high-five! ✋" << std::endl;
}