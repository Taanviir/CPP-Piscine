#include "ClapTrap.hpp"
#include <cstring>

ClapTrap::ClapTrap(): _name("") {
	std::cout << "Default constructor called for nameless ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy): _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
	std::cout << "Copy constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
	if (_name == "")
		std::cout << "Destructor called for nameless ClapTrap" << std::endl;
	else
		std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	if (this == &copy) return *this;

	std::cout << "Copy constructor called for ClapTrap " << this->_name << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " cannot attack due to insufficient energy points. 😴" << std::endl;
		return;
	} else if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has fallen. ☠️" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! ⚔️" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage. 🤕" << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " cannot attack due to insufficient energy points. 😴" << std::endl;
		return;
	} else if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has already fallen. ☠️" << std::endl;
		return;
	} else if ((this->_hitPoints + amount) > 10) {
		std::cout << "ClapTrap " << this->_name << " cannot have its hit points exceed 10." << std::endl;
		return;
	}

	std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << " hit points. 🛠️" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}