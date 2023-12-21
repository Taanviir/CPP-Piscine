#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
	_name = "Default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Default constructor called for ClapTrap" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	std::cout << "Copy constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string* name) {
	if (name == NULL || (*name).empty()) {
		std::cout << "Invalid name entered for ClapTrap, name set to \"Unknown\". ❌" << std::endl;
		_name = "Unknown";
	} else {
		_name = *name;
	}
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	if (name.empty()) {
		std::cout << "Invalid name entered for ClapTrap, name set to \"Unknown\". ❌" << std::endl;
		_name = "Unknown";
	} else {
		_name = name;
	}
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	std::cout << "Copy operator called for ClapTrap " << this->_name << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string* target) {
	if (target == NULL || (*target).empty()) {
		std::cout << "ClapTrap " << _name << " cannot attack due to invalid target. ❌" << std::endl;
		return;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot attack due to insufficient energy points. 😴" << std::endl;
		return;
	} else if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has fallen. ☠️" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! ⚔️" << std::endl;
	_energyPoints--;
}

void ClapTrap::attack(const std::string& target) {
	if (target.empty()) {
		std::cout << "ClapTrap " << _name << " cannot attack due to invalid target. ❌" << std::endl;
		return;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot attack due to insufficient energy points. 😴" << std::endl;
		return;
	} else if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has fallen. ☠️" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! ⚔️" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead, stop attacking!" << std::endl;
		return;
	} else if (_hitPoints > amount) {
		_hitPoints -= amount;
	} else if (_hitPoints <= amount) {
		_hitPoints = 0;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. 🤕" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot attack due to insufficient energy points. 😴" << std::endl;
		return;
	} else if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has already fallen. ☠️" << std::endl;
		return;
	} else if (amount == 0) {
		std::cout << "Insufficient amount of points for repairing. ❌" << std::endl;
		return;
	} else if ((_hitPoints + amount) > 10) {
		std::cout << "ClapTrap " << _name << " cannot have its hit points exceed 10." << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " repairs itself with " << amount << " hit points. 🛠️" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}