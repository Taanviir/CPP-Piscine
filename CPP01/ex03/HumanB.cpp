#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
}

HumanB::~HumanB(void) {
	return;
}

void HumanB::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType();
}

void HumanB::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}