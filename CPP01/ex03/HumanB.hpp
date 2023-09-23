#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

# include "Weapon.hpp"

class HumanB {

private:
	std::string _name;
	Weapon _weapon;

public:
	HumanB(std::string name);
	~HumanB(void);

	void attack(void);
	void setWeapon(Weapon weapon);

};

#endif