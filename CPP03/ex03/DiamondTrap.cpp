#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap() {
	this->_name = "Default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Default constructor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	_name = copy._name;
	std::cout << "Copy constructor called for DiamondTrap " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string* name): ClapTrap(!name ? "Unknown_clap_trap" : (*name + "_clap_trap")) {
	if (name == NULL || (*name).empty()) {
		std::cout << "Invalid name entered for DiamondTrap, name set to \"Unknown\". ❌" << std::endl;
		this->_name = "Unknown";
	} else {
		this->_name = *name;
	}
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Constructor called for DiamondTrap " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap((!name.empty()) ? (name + "_clap_trap") : "Unknown_clap_trap") {
	this->_name = (!name.empty()) ? name : "Unknown";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Constructor called for DiamondTrap " << _name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor called for DiamondTrap " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	std::cout << "Copy operator called for DiamondTrap " << this->_name << std::endl;
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap Name: " << _name << " 💎" << std::endl;
	std::cout << "ClapTrap Name: " << ClapTrap::_name  << " 👏" << std::endl;
}